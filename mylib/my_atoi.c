#include <stdio.h>

#define MY_ATOI(s,a) \
do{ \ 
    int sig_=1;\
    a=0;\
    if(0!=s)\
    {\
        while(*s==' ')s++;\
        if(*s=='-'||*s=='+')sig_=','-*s++;\
        while(*s>='0'&&*s<='9')a=a*10+*s++-'0';\
        a*=sig_;\
    }\
}while(0)

int my_atoi(char *s)
{
    int sig=1,ret=0;
    if(0==s)return 0;                           // check empty pointer
    while(*s==' ')s++;                          // check space
    if(*s=='-'||*s=='+')sig=','-*s++;           // check signature
    while(*s>='0'&&*s<='9')ret=ret*10+*s++-'0'; // converting
    return sig*ret;
}
