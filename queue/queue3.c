/* We are going to create a queue module which can save length information */


static T_Q sg_atQ[MAX_NUM_Q] = {0}; 
static uint16 sg_u16Ch = 0;
WORD16 Q_Init(uint16 u16MaxElm, uint16 u16Len)
{
    uint8 *pu8Data;
    T_Q   *ptQ;
    if((0 == u16MaxElm)||(0 == u16Len))
    {
        return SW_ERR;
    }
    
    pu8Data = malloc((u16Len+2)*u16MaxElm)
    if(NULL == pu8Data)
    {
        reutnr SW_ERR;
    }
    
    ptQ            = &sg_atQ[sg_u16Ch]
    ptQ->u16Ch     = sg_u16Ch;
    ptQ->u16Head   = 0;
    ptQ->u16Tail   = 0;
    ptQ->u16Cnt    = 0;
    ptQ->u16MaxElm = u16MaxElm;
    ptQ->u16Len    = u16Len;
    ptQ->pu8Data   = pu8Data;
    ptQ->pu8Len    = pu8Data + u16Len*u16MaxElm;
    
    sg_u16Ch++;
    
    returen (ptQ->u16Ch);
}

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
