/*Uso do timer 0 e timer 1 com 16F628A*/

/*
 * sim.c
 *
 *  Created on: 10/09/2014
 *      Author: cuki
 */

/*
 * sim.c
 *
 *  Created on: 10/09/2014
 *      Author: cuki
 */

/*
 * sim.c
 *
 *  Created on: 10/09/2014
 *      Author: cuki
 */

#include <16F628A.h>

#fuses NOWDT,NOPUT,INTRC_IO,NOMCLR,NOBROWNOUT,NOLVP,NOCPD,NOPROTECT
#use delay(clock=4MHz)
#use rs232(xmit=PIN_B2, baud=9600)

#define cms_mstr	PIN_A0
#define cmd_mstr	PIN_A1
#define cms_slv		PIN_A2
#define cmd_slv		PIN_A3

#define pos_mstr	PIN_B0
#define pos_slv		PIN_B1

short ctrlMstr;
short ctrlSlv;
short ctrlFusoM;
short ctrlFusoE;
short mstr_sobe;
short slv_sobe;

signed long fuso_mstr;
signed long fuso_slv;
signed long fuso_mstrAux;
signed long fuso_slvAux;

#INT_TIMER0
void isr_tmr0() {
	clear_interrupt(INT_TIMER0);
	output_toggle(pos_mstr);
	if (!ctrlFusoM)
		if (mstr_sobe)
			fuso_mstr++;
		else
			fuso_mstr--;
	ctrlFusoM = !ctrlFusoM;
}

#INT_TIMER1
void isr_tmr1() {
	clear_interrupt(INT_TIMER1);
	set_timer1(0x7FFF);
	output_toggle(pos_slv);
	if (!ctrlFusoE)
		if (slv_sobe)
			fuso_slv++;
		else
			fuso_slv--;
	ctrlFusoE = !ctrlFusoE;
}

int main(void) {

	short a = FALSE;
	short b = FALSE;
	short c = FALSE;
	short d = FALSE;

	set_timer0(0);
	setup_timer_0(T0_INTERNAL | T0_DIV_128);

	set_timer1(0x7FFF);
	setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);

	clear_interrupt(INT_TIMER0);
	clear_interrupt(INT_TIMER1);
	enable_interrupts(GLOBAL);

	printf("Mestre,Escravo\n\r");

	output_low(pos_mstr);
	output_low(pos_slv);

	while (TRUE) {

		a = input(cms_mstr);
		b = input(cmd_mstr);
		c = input(cms_slv);
		d = input(cmd_slv);

		if (a ^ b) {
			if (ctrlMstr) {
				ctrlMstr = FALSE;
				mstr_sobe = a;
				clear_interrupt(INT_TIMER0);
				set_timer0(0);
				enable_interrupts(INT_TIMER0);
			}
		} else if (!ctrlMstr) {
			ctrlMstr = TRUE;
			disable_interrupts(INT_TIMER0);
		}

		if (c ^ d) {
			if (ctrlSlv) {
				ctrlSlv = FALSE;
				slv_sobe = c;
				clear_interrupt(INT_TIMER1);
				set_timer1(0x7FFF);
				enable_interrupts(INT_TIMER1);
			}
		} else if (!ctrlSlv) {
			ctrlSlv = TRUE;
			disable_interrupts(INT_TIMER1);
		}
		if ((fuso_mstr != fuso_mstrAux) || (fuso_slv != fuso_slvAux)) {
			fuso_mstrAux = fuso_mstr;
			fuso_slvAux = fuso_slv;
			delay_us(10);
			printf("%ld,%ld\n\r", fuso_mstr, fuso_slv);

		}
	} // infinite loop
	return 0;
} // main
