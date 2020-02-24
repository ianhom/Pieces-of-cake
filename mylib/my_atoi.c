#include <stdio.h>

#define MY_ATOI(s) \
({ \ 
    int _sig=1,_max=0;\
    if(0!=s)\
    {\
        while(*s==' ')s++;\
        if(*s=='-'||*s=='+')_sig=','-*s++;\
        while(*s>='0'&&*s<='9')_max=_max*10+*s++-'0';\
    }\
    _max*=_sig;\
})

int my_atoi(char *s)
{
    int sig=1,ret=0;
    if(0==s)return 0;                           // check empty pointer
    while(*s==' ')s++;                          // check space
    if(*s=='-'||*s=='+')sig=','-*s++;           // check signature
    while(*s>='0'&&*s<='9')ret=ret*10+*s++-'0'; // converting
    return sig*ret;
}

void main(int argc, char **argv)
{
    int a[101];
    for(int i=1;i<argc;i++)
    {
        a[i]=atoi(argv[i]);
        printf("%d",a[i]);
    }
    printf("\n");
}
