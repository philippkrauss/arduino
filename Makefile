# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

BOARD_TAG    = uno
MONITOR_PORT = /dev/cu.usbserial-14110

USER_LIB_PATH=lib

ARDUINO_LIBS=MPU6050_tockn Wire PID

include /usr/local/opt/arduino-mk/Arduino.mk
