#!/bin/bash
cd build
make
DEV=$(blkid -L RPI-RP2)
sudo mount "$DEV" PICO_BOOT
sudo cp *.uf2 PICO_BOOT/
sync
