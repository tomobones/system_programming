#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define BLINK_MS 1000

// blink led at pb5

int main (void) {
    DDRB |= _BV(DDB5);
    
    while (true) {
        PORTB ^= _BV(PORTB5);
        _delay_ms(BLINK_MS);
    }
    return 0;
}

