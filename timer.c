#include<18F252.h>

#fuses HS

#use delay(clock=8MHz)
//#use rs232(baud=9600, xmit=PIN_C6)

#define tempo 14465

static long registrador;

#INT_TIMER0
void isr_timer0() {
	clear_interrupt(INT_TIMER0);
	set_timer0(tempo);
	output_toggle(PIN_C3);
}

int main(void) {
	clear_interrupt(INT_TIMER0);
	setup_timer_0(T0_DIV_256);
	set_timer0(tempo);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);
	while (TRUE){
		if (registrador != get_timer0())
			registrador = get_timer0();
	}
	return 0;
}
