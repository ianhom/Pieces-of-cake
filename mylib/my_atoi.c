#include <stdio.h>

int my_atoi(char *s)
{
    int sig=1,ret=0;
    if(0==s)return 0;                           // check empty pointer
    while(*s==' ')s++;                          // check space
    if(*s=='-'||*s=='+')sig=','-*s++;           // check signature
    while(*s>='0'&&*s<='9')ret=ret*10+*s++-'0'; // converting
    return sig*ret;
}
