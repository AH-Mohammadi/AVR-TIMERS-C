#include <avr/io.h>
//use 8 prescaler timer0 for having delay of .8s 
void T0Delay();

int main(int argc, char const *argv[])
{
    DDRB = 0xFF;

    while(1){
      T0Delay();

      PORTB = PORTB ^ 0xFF;
        }
}

void T0Delay(){

    TCNT0 = 186;
    unsigned int counter = 0;
    TCCR0A = 0x01;
    TCCR0B = (1 << CS01);
    while (counter <=3200) {
      while ((TIFR0 & (1 << TOV0)) == 0);

      counter++;
      TIFR0 = (1 << TOV0);
      TCNT0 = 186;
    }
    TCCR0B = 0x00;

    TIFR0 = 0x1;

    
}

