/******************************************************************************
* File       : queue.h
* Function   : General queue operation with length information    
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
* History    :  No.  When           Who           What
*               1    13/Aug/2018    Ian           Create
******************************************************************************/

typedef struct _T_Q
{
    uint16  u16Ch;
    uint16  u16Head;
    uint16  u16Tail;
    uint16  u16MaxElm;
    uint16  u16Len;
    uint16  u16Cnt;
    uint8  *pu8Data;
    uint8  *pu8Len;
}T_Q;

#ifndef MAX_NUM_Q
#define MAX_NUM_Q        (10)
#endif

/******************************************************************************
* Name       : WORD16 Q_Init(uint16 u16MaxElm, uint16 u16Len)
* Function   : Init a new queue, save the key information of queue and return the
*              channel number if succeed.
* Input      : uint16 u16MaxElm   1~65535   The maximum of elements in the queue
*              uint16 u16Len      1~65535   The length of each element in byte
* Output:    : None
* Return     : 1~65535   Successful operation & queue channel number.
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
******************************************************************************/
WORD16 Q_Init(uint16 u16MaxElm, uint16 u16Len);

/******************************************************************************
* Name       : WORD32 Q_En(uint16 u16Ch, uint16 u16Len, uint8 *pu8Data)
* Function   : Enqueue operation
* Input      : uint16 u16Ch       1~65535   The channel number of queue
*              uint16 u16Len      1~65535   The length of each element in byte
*              uint8 *pu8Data               The data pointer to be saved
* Output:    : None
* Return     : SW_OK     Successful operation
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
******************************************************************************/
WORD32 Q_En(uint16 u16Ch, uint16 u16Len, uint8 *pu8Data);

/******************************************************************************
* Name       : WORD32 Q_De(uint16 u16Ch, uint16 *pu16Len, uint8 *pu8Data)
* Function   : Dequeue operation
* Input      : uint16 u16Ch       1~65535   The channel number of queue
*              uint16 u16Len      1~65535   The length of each element in byte
* Output:    : uint8 *pu8Data               The data pointer to be loaded
* Return     : SW_OK     Successful operation
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
******************************************************************************/
WORD32 Q_De(uint16 u16Ch, uint16 *pu16Len, uint8 *pu8Data);

/******************************************************************************
* Name       : uint16 Q_Cnt(uint16 u16Ch)
* Function   : Return the count of current element of queue.
* Input      : uint16 u16Ch       1~65535   The channel number of queue
* Output:    : None
* Return     : 1~65535   Successful operation & the count of the element
*            : SW_ERROR  Failed operation or NONE element
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
******************************************************************************/
uint16 Q_Cnt(uint16 u16Ch);

/******************************************************************************
* Name       : uint32 Q_Empty(uint16 u16Ch)
* Function   : Check if the queue is empty
* Input      : uint16 u16Ch       1~65535   The channel number of queue
* Output:    : None
* Return     : Q_EMPTY      Queue is empty
*              Q_NOT_EMPTY  Queue is NOT empty
*            : SW_ERROR     Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
******************************************************************************/
uint32 Q_Empty(uint16 u16Ch);

/******************************************************************************
* Name       : uint32 Q_Full(uint16 u16Ch)
* Function   : Check if the queue is full
* Input      : uint16 u16Ch       1~65535   The channel number of queue
* Output:    : None
* Return     : Q_FULL       Queue is full
*              Q_NOT_FULL   Queue is NOT full
*            : SW_ERROR     Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
******************************************************************************/
uint32 Q_Full(uint16 u16Ch);
