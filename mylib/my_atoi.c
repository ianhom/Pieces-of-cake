#include <stdio.h>

int my_atoi(char *s)
{
    int sig=1,ret=0;
    if(0==s)return 0;
    while(*s==' ')s++;
    if(*s=='-'||*s=='+')sig=','-*s++;
    while(*s>='0'&&*s<='9')ret=ret*10+*s++-'0';
    return sig*ret;
}
