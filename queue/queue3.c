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
    pu8Data = malloc((u16Len+sizeof(uint16))*u16MaxElm); /* Data and length */
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
    ptQ->pu8Data   = pu8Data;                     /* Data position   */
    ptQ->pu8Len    = pu8Data + u16Len*u16MaxElm;  /* Length position */
    
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
    
    /* Check if the channel number is valid or NOT */
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    /* Check if the data pointer to be input is valid or NOT */
    if(NULL == pu8Data)
    {
        return SW_ERR;
    }
    
    ptQ = sg_atQ[u16Ch - 1];
    /* Check if the input length is valid or NOT */
    if((0 == u16Len)||(u16Len > ptQ->u16Len))
    {
        return SW_ERR;
    }
    
    /* Calculate the destination position in the queue */
    pu8Des = ptQ->pu8Data + ptQ->u16Tail * ptQ->u16Len;
    for(u16Idx = 0; u16Idx < u16Len; u16Idx++)
    {   /* Input the data into the queue */
        *(pu8Des + u16Idx) = *(pu8Data + u16Idx);
    }
    
    /* Save the length information */
    *(ptQ->pu8Len) = u16Len;
    
    /* Update the tail position */
    ptQ->u16Tail = (ptQ->u16Tail + 1) % ptQ->u16MaxElm;
    
    /* Update the elements count of the queue */
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
    
    /* Check if the channel number is valid or NOT */
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    /* Check if the output data pointer or length pointer is valid or NOT */
    if((NULL == pu8Data)||(NULL == pu16Len))
    {
        return SW_ERR;
    }
    
    ptQ = sg_atQ[u16Ch - 1];
    
    /* Restore the length information */
    *pu16Len = ptQ->u16Len + ptQ->u16Head * siezof(ptQ->u16Len);
    
    /* Calculate the source position in the queue */
    pu8Src = ptQ->pu8Data + ptQ->u16Head * ptQ->u16Len;
    for(u16Idx = 0; u16Idx < u16Len; u16Idx++)
    {   /* Output the date from the queue */
        *(pu8Data + u16Idx) = *(pu8Src + u16Idx);
    }
    
    /* Update the Head position */
    ptQ->u16Head = (ptQ->u16Head + 1) % ptQ->u16MaxElm;
    
    /* Update the count of elements in the queue */
    ptQ->u16Cnt--;
    
    return SW_OK;
}

/******************************************************************************
* Name       : uint16 Q_Cnt(uint16 u16Ch)
* Function   : Return the count of current elements of queue.
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
    /* Check if the channel number is valid or NOT */
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    /* Return the current count of elements */
    return sg_atQ[u16Ch - 1].u16Cnt;
}

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
uint32 Q_Empty(uint16 u16Ch)
{
    /* Check if the channel number is valid or NOT */
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if(0 == sg_atQ[u16Ch - 1].u16Cnt)
    {   /* If the current count of elements is 0, return EMPTY */
        return Q_EMPTY;
    }
    /* Else return NOT EMPTY */
    return Q_NOT_EMPTY;
}

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
uint32 Q_Full(uint16 u16Ch)
{
    /* Check if the channel number is valid or NOT */
    if((0 == u16Ch)||(u16Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if(sg_atQ[u16Ch - 1].u16MaxElm <= sg_atQ[u16Ch - 1].u16Cnt)
    {   /* If the current count of elements is NOT less than the maximum, return FULL */
        return Q_FULL;
    }
    /* Else return NOT FULL */
    return Q_NOT_FULL;
}

/* End of file */
