/*Uso do timer 0 com fonte externa no 18F542 (pin_a4)*/

#include<18F252.h>

#FUSES HS

#use delay(clock=8MHz)
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
