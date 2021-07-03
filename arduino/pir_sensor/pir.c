#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

#define PRESCALER 10 // 10 bits, 1024
#define CLOCK_RATE 15998976
#define COUNTER_VALUE (CLOCK_RATE >> PRESCALER) // nr timer ticks per second

// pir sensor controls led output

ISR(PCINT0_vect) {
    PORTB ^= _BV(PORTB5);
    PORTB ^= _BV(PORTB1);
}

int main (void) {

    
    DDRB |= _BV(DDB5);    // set digital pin 5 as output, control led
    DDRB |= _BV(DDB1);    // set digital pin 9 as output, control speaker
    DDRB ^= !_BV(DDB0);   // set digital pin 8 as input, control pir

    PCMSK0 |= _BV(0);     // enable ext interrupt wrt pin 8 in group 0
    PCICR |= _BV(PCIE0);  // enable ext interrupts of group 0
    sei();                // enable global interrupts

    while(true) {
    }

    return 0;
}

