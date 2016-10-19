/*
 * delay.h
 *
 *  Created on: 2016年10月19日
 *      Author: lkl03
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "board.h"

void DelayInit(uint32_t SYSCLK);
void DelayMs(uint16_t nms);
void DelayUs(uint32_t nus);

#endif /* DELAY_H_ */
