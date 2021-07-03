#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

#define TOP 2000          // one second
#define CLOCK_RATE 15998976

// pir sensor controls led output

ISR(PCINT0_vect) {
    PORTB ^= _BV(PORTB5); // toggle system led
    TCCR1B ^= _BV(CS10);  // toggle prescaler, between 256 and 0
}

int main (void) {

    
    DDRB &= ~_BV(DDB0);   // set digital pin 8 as input, control pir
    DDRB |= _BV(DDB5);    // set digital pin 5 as output, control led
    DDRB |= _BV(DDB1);    // set digital pin 9 as output, control speaker

    sei();                // enable global interrupts
    PCMSK0 |= _BV(0);     // enable ext interrupt wrt pin 8 in group 0
    PCICR |= _BV(PCIE0);  // enable group 0 in pin change interrupt controller reg

    TCCR1A |= _BV(COM1A0);// toggle
    TCCR1B |= _BV(WGM12); // ctc mode of timer 1
    //TCCR1B ^= _BV(CS12) | _BV(CS10); // prescaler set to 1024
    OCR1A = TOP;        // top value set st that normal c is generated

    while(true) {
    }

    return 0;
}

