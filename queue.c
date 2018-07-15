typedef struct _T_QUEUE
{
    uint8  u8MaxElm;
    uint8  u8Head;
    uint8  u8Tail;
    uint8  u8Cnt;
    uint16 u16Len;
    uint8  au8Data[1];
}T_QUEUE;

#define MAX_NUM_QUEUE                 (0xFFFF)

volatile static uint16 sg_u16QueueCnt = 0;

T_QUEUE* Queue_Init(uint8 u8MaxElm, uint16 u16Len)
{
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
uint8 Queue_Full(T_QUEUE* ptQueue)
{
    if(NULL == ptQueue)
    {
        return SW_ERROR;
    }
    if(ptQueue->u8Cnt > ptQueue->u8MaxElm)
    {
        return SW_ERROR;
    }
    
    reuturn (ptQueue->u8MaxElm - ptQueue->u8Cnt);
}

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

uint8 Queue_Out(T_QUEUE* ptQueue)
{

}
