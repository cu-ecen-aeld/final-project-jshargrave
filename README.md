# Overview
Link to [Overview](https://github.com/cu-ecen-aeld/final-project-jshargrave/wiki/Project-Overview).

# Build
```
./build.sh
```

# QEMU
Current start of qemu is that it hangs for some reason and never starts. Ultimately a new terminal has to be opened because it breaks the current after runnign the command.

# Install
Use the following command to copy the image to a sd card.
```
sudo dd if=buildroot/output/images/sdcard.img of=/dev/sdb bs=4M status=progress conv=fsync
```

# buildroot-rpi

This repository contains assignment starter code for buildroot based assignments for the course Advanced Embedded Software Design, ECEN 5713

We will be using rpi3

Configuration of rpi  for Buildroot:
----------------------------
Other configuration of rpi:
----------------------------
For models A, B, A+ or B+:

  $ make raspberrypi_defconfig

For model Zero (model A+ in smaller form factor):

  $ make raspberrypi0_defconfig

For model 2 B:

  $ make raspberrypi2_defconfig

For model 3 B and B+:

  $ make raspberrypi3_defconfig

For model 4 B:

  $ make raspberrypi4_defconfig
