#include "avr/interrupt.h"
#include "avr/io.h"

int main() {
    DDRB |= (1<< PB5);  // make DDRB.5 output
    OCR0A = 40;
    TCCR0A = 0x09;          // CTC mode, internal clk, no prescaler
    TIMSK0 = (1 << OCIE0A);  // enable Timer0 compare match int.
    sei();                 // enable interrupts
    DDRC = 0x00;           // make PORTC input
    DDRD = 0xFF;           // make PORTD output
    while (1)              // wait here
        PORTD = PINC;
}
ISR(TIMER0_COMPA_vect)  // ISR for Timer0 compare match
{
    PORTB ^= (1 << PB5);
}