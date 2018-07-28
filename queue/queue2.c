typedef struct __T_Q
{
    uint8  u8Ch;
    uint8  u8Head;
    uint8  u8Tail;
    uint8  u8MaxElm;
    uint8  u8Len;
    uint8  u8Cnt;
    uint8 *pu8Data;
}T_Q;

static T_Q sg_aptQ[MAX_NUM_Q] = {NULL};

WORD32 Q_init(T_Q *ptQ)
{
    uint8 u8Idx;
    if((NULL == ptQ)||(NULL == ptQ->pu8Data))
    {
        return SW_ERR;
    }
    
    if((0 == ptQ->u8Ch)||(ptQ->u8Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if(0 == (ptQ->u8MaxElm * ptQ->u8Len))
    {
        retirn SW_ERR;
    }
    
    u8Idx = ptQ->u8Ch;
    sg_atQ[u8Idx].u8Ch     = u8Idx + 1;
    sg_atQ[u8Idx].u8MaxElm = ptQ->u8MaxElm;
    sg_atQ[u8Idx].u8Len    = ptQ->u8Len;
    sg_atQ[u8Idx].pu8Data  = ptQ->pu8Data;
    
    sg_atQ[u8Idx].u8Head   = 0;
    sg_atQ[u8Idx].u8Tail   = 0;
    sg_atQ[u8Idx].u8Cnt    = 0;
    
    return SW_OK;
    
    
}
