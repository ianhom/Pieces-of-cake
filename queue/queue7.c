#include <stdio.h>
#include <stdlib.h>

typedef struct _q{int h,t,c,s,*d[0];}Q;
#define INIT(n)       ({Q *_q=0;if(n)if(_q=(Q*)malloc(sizeof(Q)+sizeof(int*)*n)){_q->h=_q->t=_q->c=0;_q->s=n;}_q;})
#define IN(q,n)       ({int _ret=0;if(q)if(q->c!=q->s){q->d[q->t]=(int*)n;q->t=(++q->t)%q->s;q->c++;_ret=1;}_ret;})
#define OUT(q)        ({int *_ret=0;if(q)if(q->c!=0){_ret=q->d[q->h];q->h=(++q->h)%q->s;q->c--;}_ret;})
#define CNT(q)        (q->c)
#define EMPTY(q)      (q->c==0)
#define FULL(q)       (q->c==q->s)

// Example
void main(int argc, char **argv)
{
    char *a[10]= {"Aa","Bb","Cc","Dd","Ee","Ff","Gg","Hh","Ii","Jj"};
    char *s=argv[1];
    int i,*temp,max=0;
    Q *q;

    while(*s>='0'&&*s<='9')max=max*10+*s++-'0';
    if(!(q=INIT(max)))
        printf("Failed to init queue!\n");
    for(i=0;i<max+1;i++) 
        if(!IN(q,a[i]))
            printf("Queue is full\n");
    for(i=0;i<max+1;i++)
    {
        if(temp=OUT(q))
            printf("%s\n",(char*)temp);
        else
            printf("Queue is empty\n");
    }
}
