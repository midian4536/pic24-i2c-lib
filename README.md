# PIC24 I2C Library

This is a lightweight I2C (Inter-Integrated Circuit) library for PIC24 microcontrollers, designed to interface with EEPROMs like the 24LC256. The library has been tested in Proteus and can be used for various I2C-based peripherals.

## Features

- Supports I2C read and write operations
- Compatible with 24LC256 EEPROM (can be extended to other I2C devices)
- Written in C for MPLAB XC16
- Tested in Proteus for verification

## Requirements

- **Hardware**
  - **PIC24F16KA102** *(or any compatible PIC24 microcontroller)* - development platform.
  - **24LC256** *(or similar I2C device)* - i2c device.
- **Software**
  - **MPLAB X** - integrated development environment (IDE) for PIC microcontrollers.
  - **XC16 Compiler** - C compiler for PIC24.
  - **Proteus** *(Optional)* - for testing.

## IO Ports

| PIC24 Pin | Function | Connected Device | Description               |
| --------- | -------- | ---------------- | ------------------------- |
| RB0       | GPIO     | LED              | Controls an indicator LED |
| RB8       | I2C SCL  | 24LC256          | I2C clock                 |
| RB9       | I2C SDA  | 24LC256          | I2C data                  |

## Source Files

- `main.c` - The primary application logic.
- `led.h` & `led.c` - LED control, useful for debugging.
- `clock.h` & `clock.c` - Clock initialization and time delay.
- `i2c.h` & `i2c.c` - I2C library.

## To-Do List

  - Add error handling mechanism.

## Author Information

  - **Author**: Yiqi Wei
  - **Affiliation**: Shanghai Jiao Tong University
  - **Contact**: yiqiwei4536@gmail.com

## References

- [PIC24F16KA102 Family Data Sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/39927c.pdf)