/*Uso do timer 1 com fonte externa no 18F45k20 (pin_c0)*/

#include<18F45k20.h>

#fuses H4

#use delay(crystal=16MHz, clock=64MHz)
#use rs232(xmit=PIN_C6, baud=9600)

int main(void) {

	long aux, aux2;

	setup_timer_1(T1_EXTERNAL | T1_DIV_BY_1);

	while (TRUE) {
		aux = get_timer1();
		if (aux != aux2) {
			aux2 = aux;
			printf("\f%lu", aux);
		}
	}

	return 0;
}
