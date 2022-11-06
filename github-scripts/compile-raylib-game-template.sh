#!/usr/bin/env bash

#set -Eeuo pipefail

###

cd $GITHUB_WORKSPACE/raylib-game-template/src

echo "running makefile."

EMCC_PATH=$GITHUB_WORKSPACE/emsdk/upstream/emscripten/emcc EMSDK_PYTHON=/usr/bin/python3 RAYLIB_PATH=$GITHUB_WORKSPACE/raylib PROJECT_NAME=index make all

# make the dir in case it doesn't exist.
mkdir -p $GITHUB_WORKSPACE/raylib-game-template/site

# if there are already files there, remove them.
rm $GITHUB_WORKSPACE/raylib-game-template/site/*

# move all the index.* files from src to the site directory.
mv ./index.* $GITHUB_WORKSPACE/raylib-game-template/site/