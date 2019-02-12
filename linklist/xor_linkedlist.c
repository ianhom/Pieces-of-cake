#include <stdio.h>
#include <stdlib.h>

typedef struct _T_NODE
{
    unsigned char u8Data;
    void *        pXorKey;
}T_NODE;

typedef struct _T_LINKED_LIST
{
    T_NODE *ptHead;
    T_NODE *ptTail;
}T_LINKED_LIST;
