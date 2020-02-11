#include <stdio.h>
#include <stdlib.h>

#if(MARCO_QUEUE)
typedef struct _q{int h,t,c,s,*d[0];}Q;
#define Q_INIT(q,n)    do{if(q=(Q*)malloc(sizeof(Q)+sizeof(int*)*n){q->h=q->t=q->c=0;q->s=n;}}while(0)
#define Q_IN(q,n)      do{if(q->c!=q->s){q->d[q->t]=(int*)n;q->t=(++q->t)%q->s;q->c++;}}while(0)
#define Q_OUT(q,n)     do{if(q->c!=0){n=q->d[q->h];q->h=(++q->h)%q->s;q->c--;}}while(0)
#define Q_CNT(q)       (q->c)
#define Q_FULL(q)      (q->c == q->s)
#define Q_EMPTY(q)     (q->c == 0)

#else
typedef struct _q
{
    int h,t,c,s,*d[0];
}Q;

Q* q_init(int n)
{
    if(!n)return NULL;
    Q *q=(Q*)malloc(sizeof(Q)+sizeof(int*)*n);
    if(NULL == q)return NULL;
    q->h=q->t=q->c=0;
    q->s=n;
    return q;
}

int q_in(Q *q, int* n)
{
    if((!q)||(q->c == q->s))
        return 0;
    q->d[q–>t]=n;
    q->t=(++q->t)%q->s;
    q->c++;
    return 1;
}

int* q_out(Q *q)
{
    int *t = NULL;
    if((!q)||(q->c == 0))
        return t;
    t = q->d[q–>h];
    q->h=(++q->h)%q->s;
    q->c--;
    return t;
}

int q_cnt(Q *q)
{
    if(!q)return -1;
    return q->c;
}

int q_deinit(Q *q)
{
    if(!q)return 0;
    free(q);
    return 1;
}

int q_full(Q *q)
{
    if(!q)return 0;
    return (q->c == q->s);
}

int q_empty(Q *q)
{
    if(!q)return 0;
    return (q->c == 0);
}
#endif
