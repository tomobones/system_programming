#include <msp430.h>
#include <stdbool.h>

#define COUNTER_VALUE 1250  //about a second


int main(void) {

    // stop the watchdog timer
    WDTCTL = WDTPW | WDTHOLD;
    //allow changes to port registers
    PM5CTL0 &= ~LOCKLPM5;
    
    //Select ACLK to use VLO clock source
    CSCTL0_H = CSKEY_H;
    CSCTL2 |= SELA__VLOCLK;
    CSCTL0_H = 0;

    P1DIR |= BIT0;  //set pin 1.0 as output
    P1OUT &= ~BIT0; //clear pin 1.0 (make it low)

    P4DIR |= BIT6;  //set pin 4.6 as output
    P4OUT |= BIT6;  //set pin 4.6 (make it high)

    //Setup the timer
    TA0CCTL0 = CCIE;
    TA0CCR0 = COUNTER_VALUE;
    TA0CTL  = TASSEL__ACLK + MC__UP + ID__8; //ACLK, Up Mode, Prescaler = 8
    TA0CTL |= TAIE;

    

    while (true) {
      _BIS_SR(LPM3_bits + GIE);
    }

}


void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A(void) {
  
  //toggle the leds
  P1OUT ^= BIT0;
  P4OUT ^= BIT6;

  //reset the timer
  TA0CTL |= TACLR;
}
