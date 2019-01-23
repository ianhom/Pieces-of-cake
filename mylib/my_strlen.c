#include <stdio.h>

#define MY_STRLEN(s,l) do{l=0;if(NULL!=s)for(;s[l]!='\0';l++);}while(0)

int my_strlen(char *s)
{
    if(NULL == s)
    {
        return 0;
    }
    int len;
    for(len=0;s[len]!='\0';len++);
    return len;
}

void main(int argc, char **argv)
{
    printf("The length of the \"%s\" is %d\n",argv[1], my_strlen(argv[1]));
    return;
}
