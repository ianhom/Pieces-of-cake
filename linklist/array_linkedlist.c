#include <stdio.h>

#define MAX  100

typedef struct _L
{
    int data;
    int next;
    int prev;
}Node;

Node a[MAX]={0};

void init(void)
{
    for(int i=0;i<MAX;i++)
    {
        a[i].data=0;
        a[i].next=0;
        a[i].prev=0;
    }
}
