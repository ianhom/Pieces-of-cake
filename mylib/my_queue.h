typedef struct _q{int h,t,c,s,*d[0];}Q;
#define Q_INIT(q,n,err)   do{if(q=(Q*)malloc(sizeof(Q)+sizeof(int*)*n)){q->h=q->t=q->c=0;q->s=n;}else{err;}}while(0)
#define Q_IN(q,n,err)     do{if(q->c<q->s){q->d[q->t]=(int*)n;q->t=(++q->t)%q->s;q->c++;}else{err;}}while(0)
#define Q_OUT(q,n,err)    do{if(q->c>0){n=q->d[q->h];q->h=(++q->h)%q->s;q->c--;}else{err;}}while(0)
#define Q_CNT(q)          (q->c)
#define Q_FULL(q)         (q->c==q->s)
#define Q_EMPTY(q)        (q->c==0)
