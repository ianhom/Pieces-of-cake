#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"

int a[1000]={ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,\
             11,12,13,14,15,16,17,18,19,20};

typedef strtuct _T
{
    strtuct _T *ptNext;
    int         data;
}N;

typedef struct _TT
{
    N *head;
    N *tail;
}NN;

static int htl = 0;
static NN *pT = NULL;

int ht_init(int l)
{
    if(!l)return 0;
    pT=(NN*)malloc(l*sizeof(NN));
    if(!pT)return 0;
    htl=l;
    for(int i=0;i<l;i++)
        pT[i].head=pt[i].tail=NULL;
    return 1;
}

int hash(int data)
{
    return data % htl;
}

N* ht_add(int data)
{
    N* ptTemp,*ptNode;
    ptNode = (N*)malloc(sizeof(N));
    if(!ptNode) return NULL;
    ptNode->data=data;
    ptNode->ptNext=NULL;
    int d = hash(data);
    ptTemp=pT[d].head;
    if(!ptTemp)
        pT[d].head=ptNode;
    else
        pt[d].tail->ptNext=ptNode;
    return pT[d].tail=ptNode;
}

void prt_ht(void)
{
    N *ptTemp;
    for(int i=0;i<htl;i++)
    {
        ptTemp=pT[i].head;
        printf("Group %4d: ",htl);
        while(ptTemp)
        {
            printf("%4d ->",ptTemp->data);
            ptTemp=ptTemp->ptNext;
        }
        printf("NULL\n");
    }
}

void main(int argc, char **argv)
{
    int d[2];
    MY_ATOI_ARGV(d);
    ht_init(d[0]);
    EFOR0(i,htl)
        ht_add(a[i]);
    prt_ht();
}
