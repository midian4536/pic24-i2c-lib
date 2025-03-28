#pragma config OSCIOFNC = ON
#pragma config FNOSC = FRCDIV

#include <xc.h>

#include "clock.h"
#include "led.h"

#include "i2c.h"

int main(void) {
    clock_init();
    led_init();
    i2c_init();

    led_shine(1, 1000);

    __delay_ms(100);

    i2c_write_byte(0x50, 0x0000, 0x07);

    __delay_ms(5);

    uint8_t read_data = i2c_read_byte(0x50, 0x0000);
    led_shine(read_data, 1000);

    while (1);
    return 0;
}
