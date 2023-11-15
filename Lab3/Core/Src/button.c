/*
 * button.c
 *
 *  Created on: Nov 12, 2023
 *      Author: MY GEAR
 */


#include "button.h"

#define BUTTON_COUNT 3

static int button_flags[BUTTON_COUNT] = {0, 0, 0};
static int KeyReg[BUTTON_COUNT][4] = {
    {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
    {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
    {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}
};
static int TimerForKeyPress = 100;

static const int button_ports[BUTTON_COUNT] = {BT1_GPIO_Port, BT2_GPIO_Port, BT3_GPIO_Port};
static const int button_pins[BUTTON_COUNT] = {BT1_Pin, BT2_Pin, BT3_Pin};

int isButtonPressed(int button){
    if(button < 1 || button > BUTTON_COUNT) return 0;
    if(button_flags[button - 1]){
        button_flags[button - 1] = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess(int button){
    if(button < 1 || button > BUTTON_COUNT) return;
    button_flags[button - 1] = 1;
}

void getKeyInput(int key){
    if(key < 1 || key > BUTTON_COUNT) return;

    int index = key - 1;
    KeyReg[index][0] = KeyReg[index][1];
    KeyReg[index][1] = KeyReg[index][2];
    KeyReg[index][2] = HAL_GPIO_ReadPin(button_ports[index], button_pins[index]);

    if((KeyReg[index][0] == KeyReg[index][1]) && (KeyReg[index][1] == KeyReg[index][2])){
        if(KeyReg[index][3] != KeyReg[index][2]){
            KeyReg[index][3] = KeyReg[index][2];
            if(KeyReg[index][2] == PRESS_STATE){
                subKeyProcess(key);
                TimerForKeyPress = 100;
            }
        } else {
            TimerForKeyPress--;
            if(TimerForKeyPress == 0){
                KeyReg[index][3] = NORMAL_STATE;
            }
        }
    }
}
