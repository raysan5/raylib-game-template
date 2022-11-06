#!/usr/bin/env bash

set -Eeuo pipefail

###

cd ./emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh