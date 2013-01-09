/*
 * timer.c
 *
 *  Created on: 07/11/2011
 *      Author: cuki
 */
#include<18F452.h>
#use delay (clock = 8MHz)
#INT_TIMER2
void timer2_isr() {
	clear_interrupt(int_timer0);
	output_toggle(pin_a0);
//	disable_interrupts(int_timer2);

}

void main(void) {
	setup_timer_2(T2_DIV_BY_1, 0, 1);

	enable_interrupts(int_timer2);
	enable_interrupts(global);

	while (true) {
//		delay_ms(800);
//		enable_interrupts(int_timer2);
	}
}
//#include<18F452.h>
//
//int cont = 0;
//
//#INT_TIMER2
//void timer2_isr() {
//	clear_interrupt(int_timer2);
//	cont++;
//	if (cont == 10) {
//		cont = 0;
//		output_bit(pin_b0, ~input_state(pin_b0));
//	}
//
//}
//
//void main(void) {
//	setup_timer_2(T2_DIV_BY_16, 233, 16);
//
//	enable_interrupts(int_timer2);
//	enable_interrupts(global);
//
//	while (true)
//		;
//}

//#include <18F452.h>
//
//#use delay(clock=8MHz)
//#include "lcd_8b.c"
//
//float tempo;
//int t0_overflow;
//
//#INT_TIMER0
//void isr_timer0() {
//  t0_overflow++;
//}
//
//#INT_TIMER1
//void isr_timer1() {
//  output_bit(PIN_C4, ~input(PIN_C4));
//}
//
//float converteTempo(long leitura) {
//
//  return  leitura * 0.000016;
//
//}
//
//void main(void) {
//
//  SETUP_TIMER_0(T0_INTERNAL | T0_DIV_16);
//  //setup_timer_0(T0_INTERNAL);
//  //tup_timer_1(T1_DIV_BY_2);
//  //  setup_timer_1(T1_DIV_BY_2 | T1_INTERNAL);
//
//  ENABLE_INTERRUPTS(INT_TIMER0);
//  //  ENABLE_INTERRUPTS(INT_TIMER1);
//  ENABLE_INTERRUPTS(GLOBAL);
//
//  lcd_init();
//  delay_ms(50);
//
//  while (true) {
//
//    //    if (!t0_overflow)
//    tempo = converteTempo(get_timer0());
//
//    printf(lcd, "\n%.5f %d", tempo, t0_overflow);
//    tempo = 0;
//    t0_overflow = 0;
//    clear_interrupt(int_timer0);
//    set_timer0(0);
//    delay_ms(300);
//  }
//
//}
