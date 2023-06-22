/*Denna fil skall inledas med att definera våra olika variabler 
som kommer att behövas utmed filens funktioner:

- Baud rate 9600
- Baud rate 115200
- Enablea TX
- Enablea RX
- Enablea UART
- Diseablea UART
- Definera stopbit
- Definera flödeskontroll
*/

#include "My_stm32f4_uart_lib.h"

#define UART_BRR_9600 0x68B;    //
#define UART_BRR_115200 0x08A;  // 
#define UART_CR1_EN 0x2000;     // |= (1<<13);  // UART Enable
#define UART_CR1_TXEN 0x08;
#define UART_CR1_RXEN 0x04;
#define UART_CR2_STOPIT 0x1800; // bit 12,13. 00 = 1, 01 = 0.5, 10 = 2
#define UART_CR3_FLWCTRL 0x80   // bit 8, 0 = disable, 1 = enable.

char c;

/*LIB_UART_Init som tar våra enumerationer för att initiera UART*/
void LIB_UART_Init (UART_BaudrateType baudrate, UART_ComType comtype )
{
    UART->CR1 &= ~UART_CR1_EN;      // DISABLE UART
    RCC->AHB1ENR |= (1<<0);         // CLK ENABLE PORTA
    RCC->APB1ENR |= (1<<17); 	    // CLK ENABLE UART2
    GPIOA->MODER &= ~0x00F0;        // RESET PIN2,PIN3
    GPIOA->MODER |= 0x00A0;         // ALT FUNCTION PIN2, PIN3
    GPIOA->AFR[0] &= ~0xFF00;       // RESET PIN2, PIN3
    GPIOA->AFR[0] |= 0x7700;        // AF07 PIN2,PIN3 
    UART->CR2 &= ~UART_CR2_STOPIT;  // STOPBIT 1
    UART->CR3 &=~ UART_CR3_FLWCTRL; //  FLWCTRL DISABLE
    
    if( baudrate == UART_BAUDRATE_9600) // sets baudrate using enumaration to given parameter
    {
        UART->BRR |= UART_BRR_9600;
    }
    else
        UART->BRR |= UART_BRR_115200;

    if(comtype == read)         // sets comtype using enumeration to given parameter
    {
        UART->CR1 &= UART_CR1_RXEN;
    }
    else if(comtype == write)
    {
        UART->CR1 &= UART_CR1_TXEN;
    }

    else
    {
         UART->CR1 &= UART_CR1_RXEN;
         UART->CR1 &= UART_CR1_TXEN;
    }

   UART->CR1 &=  UART_CR1_EN;  //ENABLE UART

}

/*LIB_UART_Read som tar en karaktär ock skriver ut den*/
char LIB_UART_Read()
{
    while(!(UART-> SR & (1<<5))){} //RXNE:Readdataregisternotempty
	return UART->DR;
}

/*LIB_UART_Write som tar karaktär som input*/
void LIB_UART_Write(char c)
{
    while(!(UART->SR & (1<<7))){} //TXE:Transmitdataregisterempty
     UART->DR = c;
}

