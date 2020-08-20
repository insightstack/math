#!/usr/bin/env bash

ROOT_DIR=$(pwd)

mkdir -p "$ROOT_DIR/build"

cd "$ROOT_DIR/build" || exit

cmake \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_MODULE_PATH=$ROOT_DIR/cmake \
..

make -j8