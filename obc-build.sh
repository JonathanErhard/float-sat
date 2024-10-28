#!/usr/bin/env bash

cd build-discovery|| exit 1
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=../corfu/extern/rodos/cmake/port/discovery.cmake .. 
make
