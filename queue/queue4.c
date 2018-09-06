/* This version has no memory copy */
#include "queue.h"

typedef struct _T_Q
{
    uint16 u16Ch;           /* Channel number of Queue, 1~65535       */
    uint16 u16MaxElm;       /* Maximum count of elements in the Queue */
    uint16 u16Head;         /* Head position of the queue             */
    uint16 u16Tail;         /* Tail position of the queue             */
    uint16 u16Cnt;          /* Count of the current elements          */
    uint8  **ppu8Data;      /* Data pointer                           */
    uint16 *p16Len;         /* Length of each data elements in bytes  */
}T_Q;

#define MAX_NUM_Q      (2)  /* Define it in application               */  

static uint16 sg_u16Cnt = 0;
static T_Q sg_atQ[MAX_NUM_Q] = {0}; 

uint32 Q_Init(uint16 u16MaxElm)
{
    T_Q *ptQ;  
    uint8 **ppu8Data;
    uint16 *pu16Len;
  
    if(0 == u16MaxElm)
    {
        return SW_ERROR;
    }
    
    ppu8Data = (uint8**)malloc(sizeof(uint8*)*u16MaxElm)
    if(NULL == ppu8Data)
    {
        PRINTF("No more memory for queue data!\r\n");
        return SW_ERROR;
    }
    
    pu16Len = (uint16*)malloc(sizeof(uint16)*u16MaxElm)
    if(NULL == pu16Len)
    {
        PRINTF("No more memory for queue data length!\r\n");
        return SW_ERROR;
    }
    
    if(0xFFFF <= sg_u16Cnt)
    {
        PRINTF("To many queues are used!\r\n");
        return SW_ERROR;
    }
    
    ptQ = &sg_atQ[sg_u16Cnt];
    
    /* Update the count of inited queue */
    sg_u16Cnt++;
    
    ptQ->u16Ch = sg_u16Cnt;
    ptQ->u16MaxElm = u16MaxElm;
    ptQ->u16Head   = 0;
    ptQ->u16Tail   = 0;
    ptQ->u16Cnt    = 0;
    ptQ->ppu8Data  = ppu8Data;
    ptQ->pu16Len   = pu16Len;    
    
    return SW_OK;
}

uint32 Q_In(uint16 u16Ch)
{
    T_Q *ptQ;  
    uint8 **ppu8Data;
    uint16 *pu16Len;
    
    if((0 == u16Ch)||(u16Ch > MAX_NUM_Q))
    {
        PRINTF("Wrong channel number!\r\n");
        return SW_ERROR;
    }
    
    return SW_OK;
}

uint32 Q_Out(uint16 u16Ch)
{
    T_Q *ptQ;  
    uint8 **ppu8Data;
    uint16 *pu16Len;
    
    if((0 == u16Ch)||(u16Ch > MAX_NUM_Q))
    {
        PRINTF("Wrong channel number!\r\n");
        return SW_ERROR;
    }
    
    return SW_OK;
}
  
