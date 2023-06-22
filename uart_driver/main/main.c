/*Här är exekveringen av vår applikation där vi ärver lib.h och därmed kan initiera
UART för att sedan skriva med UART-funktionen write i en while-loop.*/
#include "My_stm32f4_uart_lib.h"
char c;

int main()
{
 
 lIB_UART_Init(UART_BAUDRATE_9600, readwrite);

 while(1)
 {
    LIB_UART_Read(c);  // Read a character from UART
    LIB_UART_Write(c);     // Write the character back to UART

 }

}