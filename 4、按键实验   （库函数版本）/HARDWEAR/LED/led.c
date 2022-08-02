#include "led.h"
#include "stm32f10x.h"

void led_init(void){
	GPIO_InitTypeDef GPIO_InitTypeStructrue;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitTypeStructrue.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitTypeStructrue.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitTypeStructrue.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitTypeStructrue);
	GPIO_Init(GPIOE,&GPIO_InitTypeStructrue);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}

