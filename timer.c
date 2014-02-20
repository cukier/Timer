/*Uso do timer 0 com fonte externa no 18F542 (pin_a4)*/

#include<18F452.h>

#FUSES HS

#use delay(clock=8MHz)
#use rs232(xmit=PIN_C6, baud=9600)

#INT_TIMER0
void isr_timer0() {
	clear_interrupt(INT_TIMER0);
	set_timer0(252);
	output_toggle(PIN_C3);
}

int main(void) {

	setup_timer_0(T0_DIV_1 | T0_EXT_L_TO_H | T0_8_BIT);
	set_timer0(252);
	clear_interrupt(INT_TIMER0);
	enable_interrupts(INT_TIMER0 | GLOBAL);

	while (TRUE) {
		;
	}

	return 0;
}
