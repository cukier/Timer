/*Uso do pino T0CKI(PIN_A4) como contador do timer0 para 18F45K20*/

#include<18F45K20.h>

#FUSES HS
#use delay(clock=15MHz)
#use rs232(xmit=PIN_C6, baud=9600)

long aux, cont;

int main(void) {
	set_timer0(0);
	setup_timer_0(T0_EXT_H_TO_L);
	while (TRUE) {
		cont = get_timer0();
		if (aux != cont) {
			aux = cont;
			printf("\f%Lu", cont);
		}
	}
}
