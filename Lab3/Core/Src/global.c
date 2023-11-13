/*
 * global.c
 *
 *  Created on: Nov 13, 2023
 *      Author: MY GEAR
 */

#include "global.h"

int status = 0;
int horizontal_num = 0;
int vertical_num = 0;
int led_buffer [4] = {0, 0, 0, 0};
int index_led;

void display7SEG(int num){
	  switch(num){
			case 0:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
				  break;
			case 1:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
				  break;
			case 2:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				  break;
			case 3:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				  break;
			case 4:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				  break;
			case 5:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				  break;
			case 6:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				  break;
			case 7:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
				  break;
			case 8:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				  break;
			case 9:
				  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				  break;

	  }
}

void updateClockBuffer(){
	led_buffer[0] = vertical_num / 10;
	led_buffer[1] = vertical_num % 10;
	led_buffer[2] = horizontal_num / 10;
	led_buffer[3] = horizontal_num % 10;
};

void update7SEG (int index) {
	  display7SEG(led_buffer[index]);
	  switch (index){
	  case 0:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	  	  break;
	  case 2:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	  	  break;
	  case 3:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	  	  break;
	  default:
	  	  break;
	  }
};

void writeVerticalLED(int R, int G, int Y){
	HAL_GPIO_WritePin(LED_RED_V_GPIO_Port, LED_RED_V_Pin, R);
	HAL_GPIO_WritePin(LED_GREEN_V_GPIO_Port, LED_GREEN_V_Pin, G);
	HAL_GPIO_WritePin(LED_YELLOW_V_GPIO_Port, LED_YELLOW_V_Pin, Y);
};

void writeHorizontalLED(int R, int G, int Y){
	HAL_GPIO_WritePin(LED_RED_H_GPIO_Port, LED_RED_H_Pin, R);
	HAL_GPIO_WritePin(LED_GREEN_H_GPIO_Port, LED_GREEN_H_Pin, G);
	HAL_GPIO_WritePin(LED_YELLOW_H_GPIO_Port, LED_YELLOW_H_Pin, Y);
};

void countDown(){
	horizontal_num--;
	vertical_num--;
};

void setLightsTime(int vertical, int horizontal){
	horizontal_num = horizontal;
	vertical_num = vertical;
};
