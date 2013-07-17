#include<18F252.h>

#fuses HS

#use delay(clock=8MHz)
//#use rs232(baud=9600, xmit=PIN_C6)

#INT_TIMER2
void isr_timer2() {
	clear_interrupt(INT_TIMER2);
	output_toggle(PIN_C3);
}

int main(void) {
	clear_interrupt(INT_TIMER2);
	setup_timer_2(T2_DIV_BY_16, 77, 16);
	enable_interrupts(INT_TIMER2);
	enable_interrupts(GLOBAL);
	while (TRUE)
		;
	return 0;
}
