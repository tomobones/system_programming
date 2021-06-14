#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define PRESCALER 10 // 10 bits, 1024
#define CLOCK_RATE 15998976
#define COUNTER_VALUE (CLOCK_RATE >> PRESCALER) // nr timer ticks per second

// blink led at pb5

int main (void) {

    // set pb5 as output
    DDRB |= _BV(DDB5);

    // set timer normal mode
    TCNT1 = 0;
    TCCR1A = 0;
    TCCR1B = _BV(CS12) | _BV(CS10); // set prescalar to 1024
    
    while (true) {
        // polling version, buisy waiting
        while (TCNT1 < COUNTER_VALUE) {}
        TCNT1 = 0;
        PORTB ^= _BV(PORTB5);
    }
    return 0;
}

