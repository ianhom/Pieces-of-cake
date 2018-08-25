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
    uint16 *p168Len;        /* Length of each data elements in bytes  */
}T_Q;

#define MAX_NUM_Q      (2)  /* Define it in application               */  

static T_Q sg_atQ[MAX_NUM_Q] = {0}; 

uint32 Q_Init(uint16 u16MaxElm)
{
      
  
    if(0 == u16MaxElm)
    {
        return SW_ERROR;
    }
  
    
    return SW_OK;
}
