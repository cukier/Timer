#include<18F452.h>

#fuses HS,NOWDT,NOLVP,BROWNOUT,PUT

#use delay(clock=8000000)
//#use delay(clock=32MHz, crystal=8MHz)
//#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

/*#INT_TIMER0
 void isr_timer0() {
 clear_interrupt(int_timer0);
 set_timer0(0);
 output_toggle(pin_b5);
 }*/

int main(void) {

	/*	setup_timer_0(t0_internal | t0_div_1);
	 set_timer0(0);
	 clear_interrupt(int_timer0);

	 enable_interrupts(int_timer0);
	 enable_interrupts(global);

	 output_high(pin_b4);*/

	while (true) {
		output_toggle(pin_b5);
		/*output_high(pin_b5);
		 while (get_timer0())
		 ;
		 output_low(pin_b5);*/
	}
	return 0;
}
