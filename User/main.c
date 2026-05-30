#include "stm32f10x.h"
#include "Delay.h"

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    // 开 GPIOB 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // PB12 推挽输出
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
	

	while (1)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//蜂鸣器

}

}
