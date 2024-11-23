# 🧑‍💻 Twinkly Tree Firmware

## About

Nothing but bare metal (C) & AVR libraries here!

## Building & flashing

The Makefile utilized here was built on a linux machine using an [Arduino as ISP](https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoISP/) (located on the host machine at `/dev/ttyUSB0`) to flash the code to the ATTiny85. Your set up may vary and this can mostly be configured via the variables at the top of the Makefile.

Once configured, just run `make` to build & flash the firmware!

