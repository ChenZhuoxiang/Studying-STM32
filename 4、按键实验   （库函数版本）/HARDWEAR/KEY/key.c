#include "key.h"
#include "stm32f10x.h"
#include "delay.h"


void key_init(void){
	
	GPIO_InitTypeDef GPIO_InitTypeStructrue;
	GPIO_InitTypeDef GPIO_InitTypeStructureUp;
	
	GPIO_InitTypeStructrue.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitTypeStructrue.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitTypeStructrue.GPIO_Mode=GPIO_Mode_IPU;
	
	GPIO_InitTypeStructureUp.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitTypeStructureUp.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitTypeStructureUp.GPIO_Mode=GPIO_Mode_IPD;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_Init(GPIOA,&GPIO_InitTypeStructureUp);
	GPIO_Init(GPIOE,&GPIO_InitTypeStructrue);
	
}


unsigned char key_scan(unsigned char mode){
	static unsigned char key_up = 1;
	if(mode)
		key_up=1;
	if (key_up&&(KEY0==0||KEY1==0||WK_UP==1)){
		delay_ms(10);
		key_up=0;
		if (KEY0==0)return KEY0_PRES;
		else if (KEY1==0)return KEY1_PRES;
		else if (WK_UP==1)return WK_UP_PRES;		
	}else if (KEY0==1&&KEY1==1&&WK_UP==0)key_up = 1;
	return 0;
	
}


