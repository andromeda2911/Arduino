# Arduino projects

Sample sketch for Atmega1284P with Arduino IDE 2.3.3 or Arduino IDE 1.8.19


### ps2uart

Allows you to connect via the serial port Serial1 of the Arduino to send keyboard codes.
For example for a terminal.
Serial1 use pin 18 for RX et pin 19 for TX from board.
A breakout bord PS/2 is connected to pin 2 for irqpin and pin 20 for datapin.
Library PS2KeyAdavanced is used.
For ATmega32, download first bootloader and upload sketch, it's pin compatible with ATmega1284P

### terminal

Simple terminal reading input from Serial1 and redirected to Serial.

