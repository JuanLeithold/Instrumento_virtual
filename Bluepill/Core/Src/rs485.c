#include "usart.h"
#include "rs485.h"
#include <string.h>

#define uart_rs485 huart1

char rs_buftx[BUFFER_TX];
char rs_bufrx[LEN_BUF][LEN_DATA];

char dat_rx[1];
char buffer[12];
char address_rs[5];
uint8_t flag_add = 0;
uint8_t cont_buf = 0;
uint8_t cont_rx = 0;

void RS485_Send_Buffer(char* str)
{
    HAL_UART_Transmit(&uart_rs485, (uint8_t*)str, strlen(str), TIME_OUT);
}

void RS485_Flush_Buffer(void)
{
	for(uint8_t i=0; i<sizeof(rs_buftx); i++)
	{
		rs_buftx[i] = 0;
	}
}

uint8_t RS485_Read_Buffer(char buf[LEN_BUF][LEN_DATA])
{
	HAL_UART_Receive(&uart_rs485, (uint8_t*)dat_rx, 1, TIME_OUT);

    switch(dat_rx[0])
    {
        case DELIMITER:
            buffer[cont_rx] = '\0';
            strcpy(buf[cont_buf], buffer);
            if(cont_buf == 0 && flag_add == 0){
                strcpy(address_rs, buf[0]);
                flag_add = 1;
            }
            if(flag_add == 1){
                cont_buf = 0;
                flag_add = 2;
            }else{
                cont_buf++;
            }
            cont_rx = 0;
            break;

        case '\n':
            cont_rx = 0;
            cont_buf = 0;
            flag_add = 0;
            return 1;
            break;

        default:
            buffer[cont_rx++] = (char)dat_rx[0];
            break;
    }
    return 0;
}

uint8_t RS485_Read_Address(char const* add_device)
{
    return (!strcmp(address_rs, add_device)) ? 1 : 0;
}
