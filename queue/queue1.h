/******************************************************************************
* File       : queue.h
* Function   : General queue operation
* Description: To be done.           
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
* History    :  No.  When           Who           What
*               1    18/jul/2018    Ian           Create
******************************************************************************/
typedef struct _T_QUEUE
{
    uint8  u8MaxElm;
    uint8  u8Head;
    uint8  u8Tail;
    uint8  u8Cnt;
    uint16 u16Len;
    uint8  au8Data[1];
}T_QUEUE;

#define MAX_NUM_QUEUE                 (0xFFFF)

