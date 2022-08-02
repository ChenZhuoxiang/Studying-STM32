#ifndef key_h
#define key_h
#include "sys.h"

#define KEY0 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define KEY1 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define WK_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)

#define KEY0_PRES 1//KEY0按下
#define KEY1_PRES 2//KEY1按下
#define WK_UP_PRES 3//WK_UP按下

void key_init(void);
unsigned char key_scan(unsigned char);


#endif


