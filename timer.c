#include<18F252.h>

#fuses HS,NOWDT,NOLVP,BROWNOUT,PUT

//#use delay(clock=25MHz)
//#use rs232(baud=9600, xmit=PIN_C6)

#INT_TIMER0
void isr_timer0() {
	clear_interrupt(INT_TIMER0);
	output_toggle(PIN_C3);
}

int main(void) {
	clear_interrupt(INT_TIMER0);
	setup_timer_0(T0_DIV_1);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);
	while (TRUE)
		;
	return 0;
}
