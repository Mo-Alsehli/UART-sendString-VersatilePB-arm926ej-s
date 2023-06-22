/*
uart.c
Mohamed Magdi
22 JUNE 2022
*/

#include "uart.h"

// defining uart0 register
#define UART0DR *((volatile unsigned int *const)(unsigned int *)0x101F1000)

void UART_Send_String(unsigned char *P_str)
{
    while (*P_str != '\0')
    {
        UART0DR = (unsigned int)*P_str;
        P_str++;
    }
}