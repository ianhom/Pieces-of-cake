
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

WORD32 Q_Full(uint8 u8Ch)
{  
    if((0 == u8Ch)||(u8Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if(sg_atQ[u8Ch-1].u8MaxElm == sg_atQ[u8Ch-1].u8Cnt)
    {
        return SW_ERR;
    }
    
    return SW_OK;
}

WORD32 Q_Empty(uint8 u8Ch)
{

    if((0 == u8Ch)||(u8Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if(0 != sg_atQ[u8Ch-1].u8Cnt)
    {
        return SW_ERR;
    }
    
    return SW_OK;
}

WORD32 Q_EnQ(uint8 u8Ch, uint8 u8Len, uint8 *pu8Data)
{
    T_Q *ptQ;
    uint8 u8Idx;
    if((0 == u8Ch)||(u8Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if((u8Len > sg_atQ[u8Ch-1].u8Len)||(NULL == pu8Data))
    {
        return SW_ERR;
    }
    
    ptQ = &ag_atQ[u8Ch-1];
    if(ptQ->u8Cnt >= ptQMaxElm)
    {
        return SW_ERR;
    }
    
    for(u8Idx = 0; u8Idx < u8Len; u8Idx++)
    {
        *(ptQ->pu8Data + (ptQ->u8Tail*ptQ->u8Len) + u8Idx) = *(pu8Data + u8Idx)
    }
    ptQ->u8Tail = (ptQ->u8Tail + 1) % ptQ->u8MaxElm;
    ptQ->u8Cnt++;
    
    return SW_OK;
}

WORD32 Q_DeQ(uint8 u8Ch, uint8 u8Len, uint8 *pu8Data)
{
    T_Q *ptQ;
    uint8 u8Idx;
    if((0 == u8Ch)||(u8Ch >= MAX_NUM_Q))
    {
        return SW_ERR;
    }
    
    if((u8Len > sg_atQ[u8Ch-1].u8Len)||(NULL == pu8Data))
    {
        return SW_ERR;
    }
    
    ptQ = &ag_atQ[u8Ch-1];
    if(0 == ptQ->u8Cnt)
    {
        return SW_ERR;
    }
    
    for(u8Idx = 0; u8Idx < u8Len; u8Idx++)
    {
        *(pu8Data + u8Idx) = *(ptQ->pu8Data + (ptQ->u8Head*ptQ->u8Len) + u8Idx);
    }
    ptQ->u8Head = (ptQ->u8Head + 1) % ptQ->u8MaxElm;
    ptQ->u8Cnt--;
    
    return SW_OK;
}
