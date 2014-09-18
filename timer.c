/*Uso do timer 1 com fonte externa no 18F542 (pin_c0)*/

#include<18F252.h>

#fuses H4

#use delay(crystal=16MHz, clock=64MHz)
#use rs232(xmit=PIN_C6, baud=9600)

long t0, t0aux;

int main(void) {

   setup_timer_1(T1_EXTERNAL | T1_DIV_BY_1);
   set_timer1(0);

   while (TRUE) {
      t0 = get_timer1();
      if (t0 != t0aux) {
         t0aux = t0;
         printf("%ld\n\r", t0);
      }
   }
   return 0;
}
