/*
 * global.h
 *
 *  Created on: Nov 13, 2023
 *      Author: MY GEAR
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT			1
#define AUTO_RED_GREEN	2
#define AUTO_RED_YELLOW	3
#define AUTO_GREEN_RED	4
#define AUTO_YELLOW_RED	5

#define MAN_RED		12
#define MAN_YELLOW	13
#define MAN_GREEN	14

extern int status;
extern int led_buffer[4];
extern int index_led;
extern int horizontal_num;
extern int vertical_num;

extern int red;
extern int yellow;
extern int green;

void updateClockBuffer();
void update7SEG(int index);
void display7SEG(int num);
void writeVerticalLED(int R, int Y, int G);
void writeHorizontalLED(int R, int Y, int G);
void countDown();
void setLightsTime(int vertical, int horizontal);

#endif /* INC_GLOBAL_H_ */
