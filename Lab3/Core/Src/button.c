/*
 * button.c
 *
 *  Created on: Nov 12, 2023
 *      Author: MY GEAR
 */


#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;
int TimerForPressKey = 200;

int button_flag = 0;

int isButtonPressed() {
	if (button_flag == 1) {
		button_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess() {
	button_flag = 1;
}

void getKeyInput() {
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin);

	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
		if(KeyReg3 != KeyReg2) {
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESS_STATE) {
				subKeyProcess();
				TimerForPressKey = 200;
			}
		} else {
			TimerForPressKey--;
			if(TimerForPressKey == 0) {
				KeyReg3 = NORMAL_STATE;
			}
		}
	}
};
