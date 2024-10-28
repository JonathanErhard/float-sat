#!/usr/bin/env bash
cd "$(dirname "$0")"

echo "Creating binary executable..."
cd build-discovery/generated/nodes/main-node/
arm-none-eabi-objcopy -S -O binary main-node myExe.bin

echo "Flashing board..."
cp myExe.bin /media/$USER/DIS_F407VG