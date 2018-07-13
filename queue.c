typedef struct _T_QUEUE
{
    uint8  u8MaxElm;
    uint8  u8Head;
    uint8  u8Tail;
    uint8  u8Cnt;
    uint16 u16Len;
    uint8  au8Data[1];
}T_QUEUE;

volatile static uint16 sg_u16QueueCnt = 0;

T_QUEUE* Queue_Init(uint8 u8MaxElm, uint16 u16Len)
{
    T_QUEUE *ptQueue = (T_QUEUE*)malloc(u8MaxElm*u16Len+sizeof(T_QUEUE));
    if(NULL == ptQueue)
    {
        return SW_ERROR
    }
    ptQueue->u8MaxElm = u8MaxElm;
    ptQueue->u8Head   = 0;
    ptQueue->u8Tail   = 0;
    ptQueue->u8Cnt    = 0;
    pTQueue->u16Len   = u16Len;
    sg_u16QueueCnt++;
    return ptQUeue;
}
