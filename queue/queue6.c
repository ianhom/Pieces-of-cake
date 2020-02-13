#include <stdio.h>
#include <stdlib.h>

typedef struct _q{int h,t,c,s,*d[0];}Q;
#define INIT(q,n)     do{if(q=(Q*)malloc(sizeof(Q)+sizeof(int*)*n)){q->h=q->t=q->c=0;q->s=n;}}while(0)
#define IN(q,n,err)   do{if(q->c!=q->s){q->d[q->t]=(int*)n;q->t=(++q->t)%q->s;q->c++;}else err;}while(0)
#define OUT(q,n,err)  do{if(q->c!=0){n=q->d[q->h];q->h=(++q->h)%q->s;q->c--;}else err;}while(0)

// Example
void main(int argc, char **argv)
{
    char *a[10]= {"Aa","Bb","Cc","Dd","Ee","Ff","Gg","Hh","Ii","Jj"};
    char *s=argv[1];
    int i,*temp,max=0;
    Q *q;
    
    while(*s>='0'&&*s<='9')max=max*10+*s++-'0';
    INIT(q,max);
    for(i=0;i<max+1;i++) IN(q,a[i],printf("Queue is full\n"));
    for(i=0;i<max+1;i++)
    {
        OUT(q,temp,temp=NULL);
        if(temp)printf("%s\n",(char*)temp);
    }
}
