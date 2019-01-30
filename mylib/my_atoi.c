#include <stdio.h>

#define my_strlen(s,l)  do{l=0;if(NULL!=s)for(;s[l]!='\0';l++);}while(0)

int my_atoi(char *s)
{
    int ret=0;
    int l,f;
    
    my_strlen(s,l);
    for(int i=0;i<l;i++)
    {
        f=1;
        for(int j=0;j<l-1-i;j++)
            f*=10;
        ret+=(s[i]-'0')*f;
    }
    return ret;
}
