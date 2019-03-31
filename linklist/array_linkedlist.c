#include <stdio.h>

#define MAX  100
static int sg_cnt=0;  
static int index=1;//start with 1,and the first(0) node will Not used
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

int add(int data)
{
    if(sg_cnt<MAX)
    {
        a[index].data=data;
        s[index].prex=index-1;
        a[index].next=index+1;
        index++;
        sg_cnt++;
    }
    else//last one is used
    {
        for(int i=0;i<MAX;i++)
        {
            if(0==a[i].prev&&0==a[i].next)
            {
            //
            }
        }
    }
        
}
    


