/*
 * button.h
 *
 *  Created on: Nov 12, 2023
 *      Author: MY GEAR
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESS_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

int isButtonPressed(int button);

void getKeyInput(int key);

#endif /* INC_BUTTON_H_ */
