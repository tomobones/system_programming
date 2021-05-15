#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define BLINK_MS 150

int main () {
    DDRB |= 0b00100000;
    
    while (true) {
        PORTB |= 0b00100000;
        _delay_ms(BLINK_MS);

        PORTB &= ~0b00100000;
        _delay_ms(BLINK_MS);
    }
    return 0;
}

