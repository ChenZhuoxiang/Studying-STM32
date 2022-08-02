#include "stm32f10x.h"
#include "beep.h"

void beep_init(void){
	
	GPIO_InitTypeDef GPIO_InitTypeStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitTypeStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitTypeStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitTypeStructure);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	
}

