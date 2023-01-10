#!/bin/bash

wget https://raw.githubusercontent.com/zephyrproject-rtos/openocd/zephyr-20220611/contrib/60-openocd.rules
sudo cp 60-openocd.rules /etc/udev/rules.d/60-openocd.rules
sudo udevadm control --reload