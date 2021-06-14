#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define BLINK_MS 1000

// led at pb5
unsigned char *portb = 0x25;

int main (void) {
    unsigned char *ddrb = 0x24;
    *ddrb |= 0b00100000; // port5
    
    while (true) {
        *portb ^= 0b00100000; // port5
        _delay_ms(BLINK_MS);
    }
    return 0;
}

