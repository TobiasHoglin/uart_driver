/*Denna fil skall ärva ifrån driver.h filen och sedan gå vidare till att genomföra 
/två stycken enumerationskonstant-angivelser. En för UART_ComType och en för UART_BaudrateType. 
Efter detta skall den även innehålla tre deklarationer av funktioner:
1.LIB_UART_Write som tar karaktär som input
2.LIB_UART_Read som tar en karaktär ock skriver ut den
3.LIB_UART_Init som tar våra enumerationer för att initiera UART*/


#ifndef __My_stm32f4_uart_lib.h__
#define __My_stm32f4_uart_lib.h__

#include "My_stm32f_uart_driver.h"

typedef enum{
    read = 0,
    write,
    readwrite,

}UART_ComType;

typedef enum {
    UART_BAUDRATE_9600 = 0,
    UART_BAUDRATE_115200,
    
} UART_BaudrateType;

void LIB_UART_Write();
LIB_UART_Read();
void lIB_UART_Init(void);

#endif