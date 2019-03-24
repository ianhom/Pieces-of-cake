#include <stdio.h>

#define MAX  100
static int sg_cnt=0;
static int head=0;
static int tail=0;
typedef struct _L
{
    int data;
    int next;
    int prev;
}Node;

Node a[MAX]={0};

void init(void)
{
    sg_cnt=0;
    for(int i=0;i<MAX;i++)
    {
        a[i].data=0;
        a[i].next=0;
        a[i].prev=0;
    }
}


