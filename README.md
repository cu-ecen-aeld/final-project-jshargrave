# Overview
Link to [Overview](https://github.com/cu-ecen-aeld/final-project-jshargrave/wiki/Project-Overview).

# Setup
Clone down the repo and initialize submodules.
```
git clone
git submodule init
git submodule update
```

Generate the buildroot config.
```
cd buildroot
make menuconfig
save
exit
```

Copy the buildroot custom config into the generated config.
```
cd ..
cat /base_external/configs/aesd_rpi_defconfig buildroot/.config > buildroot/.config
```

Reload the config and save it again.
```
cd buildroot
make menuconfig
save
exit
```

# Build
Run the `build.sh` script to build.
```
./build.sh
```

# Install
Use the following command to copy the image to an sd card. Replace `/dev/sdb` with the mounted sd card you want to flash.
```
sudo dd if=buildroot/output/images/sdcard.img of=/dev/sdb bs=4M status=progress conv=fsync
```