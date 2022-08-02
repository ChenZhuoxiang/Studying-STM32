#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int main(void){
	
	u8 key;
	led_init();
	delay_init();
	beep_init();
	key_init();
	
	while (1){
		
		key = key_scan(1);
		if (key)
		{
			switch (key)
			{
				case KEY0_PRES:
					GPIO_SetBits(GPIOB,GPIO_Pin_5);
					GPIO_ResetBits(GPIOE,GPIO_Pin_5);
					break;
				case KEY1_PRES:
					GPIO_SetBits(GPIOE,GPIO_Pin_5);
					GPIO_ResetBits(GPIOB,GPIO_Pin_5);
					break;
			}
		}else delay_ms(10);
	}
}

