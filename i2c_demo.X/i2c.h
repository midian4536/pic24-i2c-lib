#ifndef I2C_H
#define	I2C_H

#define I2C_BAUDRATE 100000 
#define I2C_WRITE 0      
#define I2C_READ 1           

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
uint8_t i2c_restart(void);
uint8_t i2c_write(uint8_t data);
uint8_t i2c_read(uint8_t ack);
void i2c_write_byte(uint8_t dev_addr, uint16_t mem_addr, uint8_t data);
uint8_t i2c_read_byte(uint8_t dev_addr, uint16_t mem_addr);
void i2c_wait_ready(uint8_t dev_addr);

#endif

