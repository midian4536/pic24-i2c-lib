#include <xc.h>
#include "i2c.h"
#include "clock.h"

void i2c_init(void) {
    I2C1CONbits.I2CEN = 0;
    I2C1BRG = FCY / I2C_BAUDRATE - FCY / 10000000 - 1;
    I2C1CONbits.DISSLW = 1;
    I2C1CONbits.I2CEN = 1;
}

void i2c_start(void) {
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN);
}

void i2c_stop(void) {
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN);
}

uint8_t i2c_restart(void) {
    I2C1CONbits.RSEN = 1;
    while (I2C1CONbits.RSEN);
    return I2C1STATbits.ACKSTAT;
}

uint8_t i2c_write(uint8_t data) {
    I2C1TRN = data;
    while (I2C1STATbits.TRSTAT);
    return I2C1STATbits.ACKSTAT;
}

uint8_t i2c_read(uint8_t ack) {
    I2C1CONbits.RCEN = 1;
    while (!I2C1STATbits.RBF);
    uint8_t data = I2C1RCV;

    I2C1CONbits.ACKDT = ack;
    I2C1CONbits.ACKEN = 1;
    while (I2C1CONbits.ACKEN);

    return data;
}

void i2c_write_byte(uint8_t dev_addr, uint16_t mem_addr, uint8_t data) {
    i2c_start();
    i2c_write((dev_addr << 1) | I2C_WRITE);
    i2c_write((mem_addr >> 8) & 0xff);
    i2c_write(mem_addr & 0xff);
    i2c_write(data);
    i2c_stop();
}

uint8_t i2c_read_byte(uint8_t dev_addr, uint16_t mem_addr) {
    uint8_t data;

    i2c_start();
    i2c_write((dev_addr << 1) | I2C_WRITE);
    i2c_write((mem_addr >> 8) & 0xff);
    i2c_write(mem_addr & 0xff);
    i2c_restart();
    i2c_write((dev_addr << 1) | I2C_READ);
    data = i2c_read(0);
    i2c_stop();

    return data;
}

void i2c_wait_ready(uint8_t dev_addr) {
    while (1) {
        i2c_start();
        if (!i2c_write((dev_addr << 1) | I2C_WRITE)) {
            break;
        }
        i2c_stop();
        __delay_ms(1);
    }
    i2c_stop();
}
