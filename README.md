# ILI9342_T4

<p align="center">
<img src="https://github.com/vindar/ILI9342_T4/blob/main/ILI9342.jpg" height="300" />
</p>

## Optimized ILI9342(C) screen driver library for Teensy 4/4.1

This library is a modification of the [ILI9341_T4 library](https://github.com/vindar/ILI9341_T4) for working with displays using an ILI9342 or ILI9342C screen controller. 

All the fancy features (differential redraws, vsync/screen tearing protection, double buffering, DMA updates...) from the original driver are available here also. The only differences with the original library are:

1. ILI9342(C) uses half-duplex SPI communication so the usual MOSI/MISO pins are replaced by a single SDA line.
2. ILI9342(C) has non-adjustable refresh rate (around 70Hz) so the `setRefreshRate()` and `setRefeshMode()` methods are not available anymore. 
3. ILI9342(C) screen orientation differs from that of ILI9341: orientation 0 and 2 are landscape (320x240) while orientation 1 and 3 are portrait (240x320). This is because the controller refreshes the screen along the horizontal 320px scanlines

## Wiring 

The display can be connected to any SPI bus on the Teensy. The CS and DC pins can be freely chosen but *using a chip select capable teensy pin for DC (it does not matter for CS) will slightly improve the driver performance*.

Possible wirings: 

ILI9342(C) SCREEN | TEENSY 4/4.1 (SPI0) | TEENSY 4/4.1 (SPI1) |NOTE
--- | --- | --- | ---
VCC |  | | power from +3.6V to +5.5V
GND |  | | connects to ground, obviously
CS  | PIN 9 | PIN 30 | Optional (but recommended). Any digital pin will do, 255 if not connected
RESET | PIN 6 | PIN29 | Optional (but recommended). Any digital pin will do, 255 if not connected
DC | PIN 10 | PIN 0 |  Mandatory. Any pin will do but choose a CS capable pin whenever possible
SDA | PIN 11 | PIN 26| Mandatory. Must be a MOSI hardware pin (it is used for both IN/OUT communications)
SCK | PIN 13 | PIN27 | Mandatory. Must be a SCK hardware pin 
LED | | | connect to +3.3V through a small resistor (50 Ohm)

## Usage 


**Check [the tutorial for the original ILI9341_T4 library](https://github.com/vindar/ILI9341_T4/blob/main/README.md) for details on how to use the library and simply replace the name `ILI9341` by `ILI9342` everywhere...**

You may also check the [examples](https://github.com/vindar/ILI9341_T4/tree/main/examples)


## Warnings

**(1) This library only works with Teensy 4/4.1/Micromod.**

**(2) The library's sole purpose is to perform framebuffer upload from memory to the screen. It does not provide any drawing primitive. You must use another canvas library to draw directly onto the memory framebuffer. To do so, you may use my <a href="https://github.com/vindar/tgx">TGX</a> library which provides optimized drawing primitives for 2D and 3D graphics.**

