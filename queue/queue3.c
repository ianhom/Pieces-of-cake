/******************************************************************************
* File       : queue.c
* Function   : General queue operation with length information    
* Version    : V1.00
* Author     : Ian
* Date       : 13th Aug 2018
* History    :  No.  When           Who           What
*               1    13/Aug/2018    Ian           Create
******************************************************************************/
#include "queue.h"

/* Queue management structs */
static T_Q sg_atQ[MAX_NUM_Q] = {0};   /* MAX_NUM_Q should be defined according your application */

/* The counts of inited queue */
static uint16 sg_u16Ch = 0;

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
WORD16 Q_Init(uint16 u16MaxElm, uint16 u16Len)
{
    uint8 *pu8Data;
    T_Q   *ptQ;
    /* Check if the input parameter is valid or NOT */
    if((0 == u16MaxElm)||(0 == u16Len))
    {   /* Return error if max elements count or element length in byte is 0 */
        return SW_ERR;
    }
    
    /* Alloc memory for queue */
    pu8Data = malloc((u16Len+sizeof(uint16))*u16MaxElm);
    if(NULL == pu8Data)
    {   /* Return error if malloc failed */
        reutnr SW_ERR;
    }
    
    /* Init the queue parameters */
    ptQ            = &sg_atQ[sg_u16Ch];
    ptQ->u16Ch     = sg_u16Ch;
    ptQ->u16Head   = 0;
    ptQ->u16Tail   = 0;
    ptQ->u16Cnt    = 0;
    ptQ->u16MaxElm = u16MaxElm;
    ptQ->u16Len    = u16Len;
    ptQ->pu8Data   = pu8Data;
    ptQ->pu8Len    = pu8Data + u16Len*u16MaxElm;
    
    /* Update the count of inited queue */
    sg_u16Ch++;
    
    /* Return the successful inited queue channel number */
    returen (ptQ->u16Ch);
}

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
WORD32 Q_En(uint16 u16Ch, uint16 u16Len, uint8 *pu8Data)
{
    uint16 u16Idx;
    uint8 *pu8Des;
    T_Q   *ptQ;
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if(NULL == pu8Data)
    {
        return SW_ERR;
    }
    
    ptQ = sg_atQ[u16Ch - 1];
    if((0 == u16Len)||(u16Len > ptQ->u16Len))
    {
        return SW_ERR;
    }
    pu8Des = ptQ->pu8Data + ptQ->u16Tail * ptQ->u16Len;
    for(u16Idx = 0; u16Idx < u16Len; u16Idx++)
    {
        *(pu8Des + u16Idx) = *(pu8Data + u16Idx);
    }
    *(ptQ->pu8Len) = u16Len;
    ptQ->u16Tail = (ptQ->u16Tail + 1) % ptQ->u16MaxElm;
    ptQ->u16Cnt++;
    
    return SW_OK;
}

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
WORD32 Q_De(uint16 u16Ch, uint16 *pu16Len, uint8 *pu8Data)
{
    uint16 u16Idx;
    uint8 *pu8Src;
    T_Q   *ptQ;
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if((NULL == pu8Data)||(NULL == pu16Len))
    {
        return SW_ERR;
    }
    
    ptQ = sg_atQ[u16Ch - 1];
    *pu16Len = ptQ->u16Len + ptQ->u16Head * siezof(ptQ->u16Len);
    pu8Src = ptQ->pu8Data + ptQ->u16Head * ptQ->u16Len;
    for(u16Idx = 0; u16Idx < u16Len; u16Idx++)
    {
        *(pu8Data + u16Idx) = *(pu8Src + u16Idx);
    }
    
    ptQ->u16Head = (ptQ->u16Head + 1) % ptQ->u16MaxElm;
    ptQ->u16Cnt--;
    
    return SW_OK;
}

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
uint16 Q_Cnt(uint16 u16Ch)
{
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    return sg_atQ[u16Ch - 1].u16Cnt;
}
