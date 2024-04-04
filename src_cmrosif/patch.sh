#!/bin/bash

cd "$(dirname "$0")" && pwd

VER_TARGET=${1:-./CM_12}
SRC_DIR=${2:-../src}

patch -r- -u -d "${SRC_DIR}" < "${VER_TARGET}/CMRosIF.patch"