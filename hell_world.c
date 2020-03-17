#include <stdio.h>
#define SZ (sizeof(int)*sizeof(long long))
#define FUNC(n) n##s(const char *s)
static const char S[5] = {0110,69,0x4C,0B1001100,sizeof(char)};
int FUNC(put)
{
    char a;
    int b=0;
    while(*s!='\0')
    {
        putchar(a=*s++);
        if((a!=S[b])&&(a!=(S[b]+SZ)))b=0;
        else if(b<3)b++;
        else if(*(s)!=a+3)putchar(a+3);
    }
    putchar('\n');
    return 1;
}

void main(int argc, char **argv)
{
    printf("Hell world!\n");   // should print "Hello world!"
    printf("hell world!\n");   // should print "Hello world!"
    printf("HELL world!\n");   // should print "HELLO world!"
    printf("Hello world!\n");  // should print "Hello world!"
    printf("%s\n",argv[1]);
}
