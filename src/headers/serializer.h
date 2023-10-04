// https://www.gamedev.net/forums/topic/687035-serialization-libraries-in-c/5335190/

#pragma once
#ifndef MEM_ALOC
#define MEM_ALOC(x) malloc(x)
#endif // !MEM_ALOC


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//make sure that there's no element padding, which would interfere with the layout of structures in memory
#pragma pack(1)

typedef struct {
	unsigned short major;
	unsigned short minor;
} VersionNumber;

const VersionNumber VERSION = { 1, 0 };

typedef struct {
	unsigned int fourcc;
	VersionNumber ver;
} SaveHeader;

void save_string(const char* str, FILE* fp) {
	unsigned int len = (unsigned int)strlen(str);
	//record string length
	fwrite(&len, sizeof(unsigned int), 1, fp);
	//record string
	fwrite(str, sizeof(char), len, fp);
}

void load_string(char** pstr, FILE* fp) {
	//get length
	unsigned int len;
	size_t err = fread(&len, sizeof(unsigned int), 1, fp);
	if (len == 0) { return; }

	//allocate and read
	char* str = (char*)MEM_ALOC(len + 1); //allocate an additional byte
	if (str == NULL) { return; }
	
	err = fread(str, sizeof(char), len, fp);
	if (err) { return; }
	
	str[len] = 0; //remember to add the terminating zero
	*pstr = str;
}

void save_game(void* data, const char* filename) {
	SaveHeader header = { 0 };
	header.fourcc = 'SAVF';
	memcpy(&header.ver, &VERSION, sizeof(header.ver));

	FILE* fp;
	fopen_s(&fp, filename, "wb");
	if (fp == 0) { return; }

	//write header
	size_t err = fwrite(&header, sizeof(header), 1, fp);

	/*
	
	size_t PARTY_POD_SECTION_LENGTH = sizeof(unsigned int) + (sizeof(int) * 2);
	fwrite(party, PARTY_POD_SECTION_LENGTH, 1, fp);

	//Item is POD (plain-old-data), so we can just dump the whole array
	fwrite(party->inventory, sizeof(Item), party->itemCt, fp);
	
	//Party members have variable length strings, so we need to save them individually

	size_t PARTYMEMBER_POD_SECTION_LENGTH = sizeof(unsigned char) + (sizeof(short) * 2);
	for(int i = 0; i < party->member_count; i++) {
		fwrite(&party->members[i], PARTYMEMBER_POD_SECTION_LENGTH, 1, fp);
		save_string(&party->members[i]->name, fp);
	}
	
	*/

	fclose(fp);
}



void load_game(void* data, const char* filename) {
	FILE* fp;
	fopen_s(&fp, filename, "rb");
	if (fp == NULL) { return; }

	SaveHeader header;
	fread(&header, sizeof(header), 1, fp);

	if (header.fourcc == 'FVAS') {
		printf("Endian mismatch!\n");
		exit(1);
	}

	if (header.fourcc != 'SAVF') {
		printf("Invalid savefile!\n");
		exit(1);
	}

	if (memcmp(&header.ver, &VERSION, sizeof(VERSION)) != 0) {
		printf("Savefile version mismatch!\n");
		exit(1);
	}

	/*
	size_t PARTY_POD_SECTION_LENGTH = sizeof(unsigned int) + (sizeof(int) * 2);
	fread(party, PARTY_POD_SECTION_LENGTH, 1, fp);

	//allocate for the inventory and just read it all in at once, since it's POD
	party->inventory = malloc(sizeof(Item) * party->itemCt);
	fread(party->inventory, sizeof(Item), party->itemCt, fp);

	//load party members individually since they're non-POD
	party->members = malloc(sizeof(PartyMember) * party->memberCt);
	for(int i = 0; i < party->memberCt; i++) {
		fread(&party->members[i], PARTYMEMBER_POD_SECTION_LENGTH, 1, fp);
		loadString(&party->members[i]->name, fp);
	}
	*/
	fclose(fp);
}