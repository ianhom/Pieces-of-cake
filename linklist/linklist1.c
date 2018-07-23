typedef struct __NODE
{
    struct __NODE *ptNext;
    uint8          au8Data[1];
}NODE;

static NODE sg_ptHead = NULL;
static NODE sg_ptTail = NULL;

void LinkList_Init(void)
{
    sg_ptHead = NULL;
    sg_ptTail = NULL;
    return;
}

NODE* LinkList_Add_Node(uint16 u16Len, uint8 *pu8Data)
{
    NODE *ptNode;
    NODE *ptTemp = sg_ptHead;
    uint16 u16Index;
    if((pu8Data == NULL) || (0 == u16Len))
    {
        return NULL;
    }
    
    ptNode = (NODE*)malloc(sizeof(NODE)+uc6Len);
    if(NULL != ptNode)
    {
        ptNode->ptNext = NULL;
        for(u16Index = 0; u16Index < u16Len; u16Index++)
        {
            ptNode->au8Data[u16Index] = pu8Data[u16Data];
        }
        
        sg_ptTail = ptNode;
        if(NULL == sg_ptHead)
        {
            sg_ptHead = ptNode;
            return ptNode;
        }
        while(ptTemp->ptNext)
        {
            ptTemp = ptTemp->ptNext;
        }
        ptTemp->ptNext = ptNode;
    }
    return ptNode;
}
