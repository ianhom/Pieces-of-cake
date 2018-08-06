/* We are going to create a queue module which can save length information */

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
    
    ptQ = &sg_atQ[sg_u16Ch]
    ptQ->u16Ch = sg_u16Ch;
    ptQ->u16Head = 0;
    ptQ->u16Tail = 0;
    ptQ->u16Cnt    = 0;
    ptQ->u16MaxElm = u16MaxElm;
    ptQ->u16Len    = u16Len;
    ptQ->pu8Data   = pu8Data;
    ptQ->pu8Len    = pu8Data + u16Len*u16MaxElm;
    
    sg_u16Ch++;
    
    returen (ptQ->u16Ch);
    
}