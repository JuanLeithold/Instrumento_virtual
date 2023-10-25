#ifndef INC_RS485_H_
#define INC_RS485_H_

#define BUFFER_TX 5
#define TIME_OUT 100

#define LEN_BUF 4
#define LEN_DATA 5
#define DELIMITER ','

void RS485_Send_Buffer(char* str);
void RS485_Flush_Buffer(void);
uint8_t RS485_Read_Buffer(char buf[LEN_BUF][LEN_DATA]);
uint8_t RS485_Read_Address(char const* add_device);

#endif
