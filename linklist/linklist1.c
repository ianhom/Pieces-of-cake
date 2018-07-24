/******************************************************************************
* File       : linklist1.c
* Function   : Basic linklist function.
* Description: One-way linklist, Init/Add/Del/Count.          
* Version    : V1.00
* Author     : Ian
* Date       : 24th Jul 2018
* History    :  No.  When           Who           What
*               1    24/Jul/2018    Ian           Create
******************************************************************************/

typedef struct __NODE
{
    struct __NODE *ptNext;
    uint8          au8Data[1];
}NODE;

static NODE sg_ptHead = NULL;
static NODE sg_ptTail = NULL;

/******************************************************************************
* Name       : void LinkList_Init(void)
* Function   : Init the linklist
* Input      : None
* Output:    : None
* Return     : None
* Description: In this function, Head and tail pointer will be inited with
*              NULL as there is no node in the linklist.
* Version    : V1.00
* Author     : Ian
* Date       : 24th Jul 2018
******************************************************************************/
void LinkList_Init(void)
{
    sg_ptHead = NULL;
    sg_ptTail = NULL;
    return;
}

/******************************************************************************
* Name       : NODE* LinkList_Add_Node(uint16 u16Len, uint8 *pu8Data)
* Function   : 
* Input      : None
* Output:    : None
* Return     : None
* Description: 
* Version    : V1.00
* Author     : Ian
* Date       : 24th Jul 2018
******************************************************************************/
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

/******************************************************************************
* Name       : NODE* LinkList_Del_Node(NODE *ptNode)
* Function   : 
* Input      : None
* Output:    : None
* Return     : None
* Description: 
* Version    : V1.00
* Author     : Ian
* Date       : 24th Jul 2018
******************************************************************************/
NODE* LinkList_Del_Node(NODE *ptNode)
{
    if(NULL == ptNode)
    {
        return NULL;
    }
    
    if(sg_ptHead == ptNode)
    {
        sg_ptHead = ptNode->ptNext;
    }
}
