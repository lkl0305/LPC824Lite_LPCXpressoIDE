/*
===============================================================================
 Name        : usart0_test.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "delay/delay.h"

// TODO: insert other definitions and declarations here

const uint8_t txBuffer[] = "Hello, world! this is a test of UART0!\r\n";
/***********************************************************
 * 设置P0.18和P0.19为USART0的引脚
 * 配置为数据位8，停止位1，无校验，波特率115200bps，
 ***********************************************************/
void Uart0_Init(void)
{
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_SWM);

	Chip_SWM_DisableFixedPin(SWM_FIXED_ADC7);
	Chip_SWM_DisableFixedPin(SWM_FIXED_ADC8);

	Chip_Clock_SetUARTClockDiv(1);

	Chip_SWM_MovablePinAssign(SWM_U0_TXD_O, 18);
	Chip_SWM_MovablePinAssign(SWM_U0_RXD_I, 19);

	Chip_Clock_DisablePeriphClock(SYSCTL_CLOCK_SWM);

	Chip_UART_Init(LPC_USART0);
	Chip_UART_ConfigData(LPC_USART0, UART_CFG_DATALEN_8 | UART_CFG_PARITY_NONE | UART_CFG_STOPLEN_1);
	Chip_Clock_SetUSARTNBaseClockRate((115200 * 6 * 16), true);
	Chip_UART_SetBaud(LPC_USART0, 115200);
	Chip_UART_Enable(LPC_USART0);
	Chip_UART_TXEnable(LPC_USART0);
}

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here
    DelayInit(SystemCoreClock);

    Uart0_Init();

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	Chip_UART_SendBlocking(LPC_USART0, txBuffer, sizeof(txBuffer));
    	DEBUGSTR("Hello, world!\r\n");
    	DelayMs(2000);
        i++ ;
    }
    return 0 ;
}
