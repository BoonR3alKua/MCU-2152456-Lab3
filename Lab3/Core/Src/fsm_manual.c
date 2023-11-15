/*
 * fsm_manual.c
 *
 *  Created on: Nov 13, 2023
 *      Author: MY GEAR
 */

#include "fsm_manual.h"

int red_temp;
int yellow_temp;
int green_temp;

void saveTempTime(){
    red_temp = red;
    yellow_temp = yellow;
    green_temp = green;
}

void fsm_manual_run(){
    switch (status) {
        case MAN_RED:
            setLightsTime(red_temp, 1);
            if (timer3_flag == 1) {
                HAL_GPIO_TogglePin(LED_RED_H_GPIO_Port, LED_RED_H_Pin);
                HAL_GPIO_TogglePin(LED_RED_V_GPIO_Port, LED_RED_V_Pin);
        		updateClockBuffer();
        		update7SEG(index_led);
        		index_led++;
        		if(index_led >= 4) index_led = 0;
                setTimer3(100);
            }
            if (isButtonPressed(1)) {
                writeHorizontalLED(SET, SET, SET);
                writeVerticalLED(SET, SET, SET);
                setTimer3(100);
                status = MAN_YELLOW;
            }
            if (isButtonPressed(2)) {
                red_temp = (red_temp < 99) ? red_temp + 1 : red;
            }
            if (isButtonPressed(3)) {
                red = red_temp;
                green = red - yellow;
                status = INIT;
            }
            break;
		case MAN_YELLOW:
			setLightsTime(yellow_temp, 2);
			if(timer3_flag == 1){
				HAL_GPIO_TogglePin(LED_YELLOW_H_GPIO_Port, LED_YELLOW_H_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW_V_GPIO_Port, LED_YELLOW_V_Pin);
				updateClockBuffer();
				update7SEG(index_led);
				index_led++;
				if(index_led >= 4) index_led = 0;
				setTimer3(100);
			}
			if(isButtonPressed(1) == 1){
				writeHorizontalLED(SET,SET,SET);
				writeVerticalLED(SET,SET, SET);
				setTimer3(100);
				status = MAN_GREEN;
			}
			if(isButtonPressed(2) == 1){
				yellow_temp = (yellow_temp < 99) ? yellow_temp + 1 : yellow;
			}
			if(isButtonPressed(3) == 1){
				yellow = yellow_temp;
				red = green + yellow;
				status = INIT;
			}
			break;
		case MAN_GREEN:
			setLightsTime(green_temp, 3);
			if(timer3_flag == 1){
				HAL_GPIO_TogglePin(LED_GREEN_H_GPIO_Port, LED_GREEN_H_Pin);
				HAL_GPIO_TogglePin(LED_GREEN_V_GPIO_Port, LED_GREEN_V_Pin);
				updateClockBuffer();
				update7SEG(index_led);
				index_led++;
				if(index_led >= 4) index_led = 0;
				setTimer3(100);
			}
			if(isButtonPressed(1) == 1){
				writeHorizontalLED(SET,SET,SET);
				writeVerticalLED(SET,SET, SET);
				status = INIT;
			}
			if(isButtonPressed(2) == 1){
				green_temp = (green_temp < 99) ? green_temp + 1 : green;
			}
			if(isButtonPressed(3) == 1){
				green = green_temp;
				red = green + yellow;
				status = INIT;
			}
			break;
		default:
			saveTempTime();
			break;
	}
}
