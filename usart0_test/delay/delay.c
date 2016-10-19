/*
 * delay.c
 *
 *  Created on: 2016年10月19日
 *      Author: lkl03
 */

#include "delay/delay.h"

static uint8_t  facUs=0;
static uint16_t facMs=0;

void DelayInit(uint32_t SYSCLK)
{
    facUs=(uint8_t)(SYSCLK / 1000000);
    facMs =(uint16_t)(SYSCLK / 1000);
}

void DelayUs(uint32_t nus)
{
    uint32_t temp;
    SysTick->LOAD = nus * facUs;
    SysTick->VAL = 0x00;
    SysTick->CTRL = 0x01;
    do
    {
         temp = SysTick->CTRL;
    }
    while(temp & 0x01 && !(temp & (1 << 16)));
    SysTick->CTRL = 0x00;
    SysTick->VAL = 0x00;
}


void DelayMs(uint16_t nms)
{
    uint32_t temp;
    SysTick->LOAD = nms * facMs;
    SysTick->VAL=0x00;
    SysTick->CTRL = 0x01;
    do
    {
         temp = SysTick->CTRL;
    }
    while(temp & 0x01 && !(temp &(1<<16)));

    SysTick->CTRL = 0x00;
    SysTick->VAL = 0x00;
}
