/******************************************************************************
* File       : queue.c
* Function   : General queue operation     
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
* History    :  No.  When           Who           What
*               1    18/jul/2018    Ian           Create
******************************************************************************/
#include "queue.h"

/* Queue counter */
volatile static uint16 sg_u16QueueCnt = 0;

/******************************************************************************
* Name       : T_QUEUE* Queue_Init(uint8 u8MaxElm, uint16 u16Len)
* Function   : Init a new queue
* Input      : uint8  u8MaxElm    1~255     The maximum of elements in the queue
*              uint16 u16Len      1~65535   The length of each element in byte
* Output:    : None
* Return     : SW_OK     Successful operation
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
******************************************************************************/
T_QUEUE* Queue_Init(uint8 u8MaxElm, uint16 u16Len)
{
    if((0 == u8MaxElm)||(0 == u16Len))
    {
        return SW_ERROR;
    }
    T_QUEUE *ptQueue = (T_QUEUE*)malloc(u8MaxElm*u16Len+sizeof(T_QUEUE));
    if(NULL == ptQueue)
    {
        return SW_ERROR;
    }
    ptQueue->u8MaxElm = u8MaxElm;
    ptQueue->u8Head   = 0;
    ptQueue->u8Tail   = 0;
    ptQueue->u8Cnt    = 0;
    pTQueue->u16Len   = u16Len;
    if(MAX_NUM_QUEUE != sg_u16QueueCnt)
    {
        sg_u16QueueCnt++;
    }
    return ptQUeue;
}

/******************************************************************************
* Name       : uint8 Queue_Deinit(T_QUEUE* ptQueue)
* Function   : Deinit a new queue
* Input      : T_QUEUE* ptQueue             The queue to be deinited
* Output:    : None
* Return     : SW_OK     Successful operation
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
******************************************************************************/
uint8 Queue_Deinit(T_QUEUE* ptQueue)
{
    if(NULL == ptQueue)
    {
        return SW_ERROR;
    }
    free(ptQueue);
    if(sg_u16QueueCnt)
    {    
        sg_u16QueueCnt--;
    }
    return SW_OK;
}

/******************************************************************************
* Name       : uint8 Queue_Full(T_QUEUE* ptQueue)
* Function   : Check if the queue if full or NOT
* Input      : T_QUEUE* ptQueue             The queue to be checked
* Output:    : None
* Return     : 1~255     Rest elements
*            : SW_ERROR  Failed operation or Full
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
******************************************************************************/
uint8 Queue_Full(T_QUEUE* ptQueue)
{
    if(NULL == ptQueue)
    {
        return SW_ERROR;
    }
    if(ptQueue->u8Cnt >= ptQueue->u8MaxElm)
    {
        return SW_ERROR;
    }
    
    reuturn (ptQueue->u8MaxElm - ptQueue->u8Cnt);
}

/******************************************************************************
* Name       : uint8 Queue_Empty(T_QUEUE* ptQueue)
* Function   : Init a new queue
* Input      : uint8  u8MaxElm    1~255     The maximum of elements in the queue
*              uint16 u16Len      1~65535   The length of each element in byte
* Output:    : None
* Return     : SW_OK     Successful operation
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
******************************************************************************/
uint8 Queue_Empty(T_QUEUE* ptQueue)
{
    if(NULL == ptQueue)
    {
        return SW_ERROR;
    }
    if (0 == ptQueue->u8Cnt)
    {
        return SW_OK;
    }
    return SW_ERROR;
}

/******************************************************************************
* Name       : uint8 Queue_In(T_QUEUE* ptQueue, uint8 *pu8Data, uint16 u16Len)
* Function   : Init a new queue
* Input      : uint8  u8MaxElm    1~255     The maximum of elements in the queue
*              uint16 u16Len      1~65535   The length of each element in byte
* Output:    : None
* Return     : SW_OK     Successful operation
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
******************************************************************************/
uint8 Queue_In(T_QUEUE* ptQueue, uint8 *pu8Data, uint16 u16Len)
{
    uint16 u16Index;
    if((NULL == ptQueue)||(NULL == pu8Data)||(u16Len > ptQUeue->u16Len))
    {
        return SW_ERROR;
    }
    if(ptQueue->u8Cnt >= ptQueue->u8MaxElm)
    {
        return SW_ERROR;
    }
    for(u16Index = 0; u16Index < u16Len; u16Index++)
    {
        ptQueue->au8Data[u16Index] = pu8Data[u16Index];
    }
    ptQueue->u8Tail = (ptQueue->u8Tail + 1) % ptQueue->u8MaxElm;
    ptQueue->u8Cnt++;
    
    return SW_OK;
}

/******************************************************************************
* Name       : BYTE Queue_Out(T_QUEUE* ptQueue, uint8 *pu8Data, uint16 u16Len)
* Function   : Init a new queue
* Input      : uint8  u8MaxElm    1~255     The maximum of elements in the queue
*              uint16 u16Len      1~65535   The length of each element in byte
* Output:    : None
* Return     : SW_OK     Successful operation
*            : SW_ERROR  Failed operation
* Version    : V1.00
* Author     : Ian
* Date       : 18th Jul 2018
******************************************************************************/
BYTE Queue_Out(T_QUEUE* ptQueue, uint8 *pu8Data, uint16 u16Len)
{
    uint16 u16Index;
    if((NULL == ptQueue)||(NULL == pu8Data)||(u16Len > ptQUeue->u16Len))
    {
        return SW_ERROR;
    }
    
    if(0 == ptQueue->u8Cnt)
    {
        return SW_ERROR;
    }
    for(u16Index = 0; u16Index < u16Len; u16Index++)
    {
        pu8Data[u16Index] = ptQueue->au8Data[u16Index];
    }
    ptQueue->u8Head = (ptQueue->u8Head + 1) % ptQueue->u8MaxElm;
    ptQueue->u8Cnt--;
    return SW_OK;
}

/* End of file */
