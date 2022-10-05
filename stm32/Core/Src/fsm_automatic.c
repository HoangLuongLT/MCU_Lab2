/*
 * fsm_automatic.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Admin
 */

#include "main.h"
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
			//HAL_GPIO_WritePin(GPIOA, LED_R_Pin, 0);
			if(timer0_flag==1){
				status = AUTO_RED;
				setTimer0(500);
			}
			break;
		case AUTO_RED:
			if(timer0_flag==1){
				status = AUTO_GREEN;
				setTimer0(300);
			}
			break;
		case AUTO_GREEN:
			if(timer0_flag==1){
				status = AUTO_YELLOW;
				setTimer0(200);
			}
			break;
		case AUTO_YELLOW:
			if(timer0_flag==1){
				status = AUTO_RED;
				setTimer0(500);
			}
			break;
		default: break;
	}
}
