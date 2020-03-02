typedef struct _q{int h,t,c,s,*d[0];}Q;
#define Q_INIT(n)   ({Q *_q=0;if(n)if(_q=(Q*)malloc(sizeof(Q)+sizeof(int*)*n)){_q->h=_q->t=_q->c=0;_q->s=n;}_q;})
#define Q_IN(q,n)   ({int _ret=0;if(q)if(q->c<q->s){q->d[q->t]=(int*)n;q->t=(++q->t)%q->s;q->c++;_ret=1;}_ret;})
#define Q_OUT(q,n)  ({int *_ret=0;if(q)if(q->c>0){_ret=q->d[q->h];q->h=(++q->h)%q->s;q->c--;}_ret;})
#define Q_CNT(q)    (q->c)
#define Q_FULL(q)   (q->c==q->s)
#define Q_EMPTY(q)  (q->c==0)
