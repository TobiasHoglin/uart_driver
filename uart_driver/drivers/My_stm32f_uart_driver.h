/*Denna fil skall definera våra så kallade utgångsbaser för korrekt kommunikationsbuss 
samt USART-periferin. Den skall sedan gå vidare och definera en struct som innehåller 
registrena för USART*/

#ifndef	__MY_STM32F4_UART_DRIVER_H__
#define __MY_STM32F4_UART_DRIVER_H__
#include "../my_stm32f4_gpio_driver.h"

#define		APB1_BASE			0x40000000U			// start adress APIB1 peripheral buss
#define 	USART2_BASE		(APB1_BASE + 0x4400U)  //Start adress UASRT2 registers

#define		__UART			volatile

typedef struct
{
	__UART	uint32_t SR;
	__UART	uint32_t DR;
	__UART	uint32_t BRR;
	__UART 	uint32_t CR1;
	__UART 	uint32_t CR2;
	__UART 	uint32_t CR3;
	__UART	uint32_t GTPR;

}UART_TypeDef;

#define 	UART			((UART_TypeDef *)USART2_BASE)

#endif



