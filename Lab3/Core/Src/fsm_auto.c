/*
 * fsm_auto.c
 *
 *  Created on: Nov 13, 2023
 *      Author: MY GEAR
 */

#include "fsm_auto.h"

int red = 5;
int yellow = 2;
int green = 3;

int index_led = 0;

void fsm_auto_run() {
	switch (status) {
		case INIT:
			writeVerticalLED(SET, SET, SET);
			writeHorizontalLED(SET, SET, SET);

			setTimer1(green * 1000);
			setTimer2(1000);
			setTimer3(100);
			setLightsTime(red, green);
			status = AUTO_RED_GREEN;
			break;
		case AUTO_RED_GREEN:
			writeVerticalLED(RESET, SET, SET);
			writeHorizontalLED(SET, RESET, SET);

			if(timer1_flag == 1) {
				setTimer1(yellow * 1000);
				setLightsTime(yellow, yellow);
				status = AUTO_RED_YELLOW;
			}
			if(timer2_flag == 1) {
				countDown();
				setTimer2(1000);
			}
			break;
		case AUTO_RED_YELLOW:
			writeVerticalLED(RESET, SET, SET);
			writeHorizontalLED(SET, SET, RESET);

			if(timer1_flag == 1) {
				setTimer1(green * 1000);
				setLightsTime(green, red);
				status = AUTO_GREEN_RED;
			}
			if(timer2_flag == 1) {
				countDown();
				setTimer2(1000);
			}
			break;
		case AUTO_GREEN_RED:
			writeVerticalLED(SET, RESET, SET);
			writeHorizontalLED(RESET, SET, SET);

			if(timer1_flag == 1) {
				setTimer1(yellow * 1000);
				setLightsTime(yellow, yellow);
				status = AUTO_YELLOW_RED;
			}
			if(timer2_flag == 1) {
				countDown();
				setTimer2(1000);
			}
			break;
		case AUTO_YELLOW_RED:
			writeVerticalLED(SET, SET, RESET);
			writeHorizontalLED(RESET, SET, SET);

			if(timer1_flag == 1) {
				setTimer1(green * 1000);
				setLightsTime(red, green);
				status = AUTO_RED_GREEN;
			}
			if(timer2_flag == 1) {
				countDown();
				setTimer2(1000);
			}
			break;
	}
	if(timer3_flag == 1){
		updateClockBuffer();
		update7SEG(index_led++);
		if(index_led >= 4) index_led = 0;
		setTimer3(100);
	}
}
