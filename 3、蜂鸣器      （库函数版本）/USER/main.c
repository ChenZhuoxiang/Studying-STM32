#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "beep.h"

int main(void){
	led_init();
	delay_init();
	beep_init();
	
	while (1){
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);		
		delay_ms(500);
		
		GPIO_SetBits(GPIOE,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		GPIO_SetBits(GPIOB,GPIO_Pin_8);		
		delay_ms(500);
	}
}

