/*
main.c
Mohamed Magdi
22 June 2023
*/

// #include "uart.h"

unsigned char *str_buffer = "UART Recieved String < Embedded Is Fun>";

int main()
{
    UART_Send_String(str_buffer);

    return 0;
}