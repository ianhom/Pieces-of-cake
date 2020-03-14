#include <stdio.h>
static cs="Hell ";
int puts(const char *s)
{
    int len = hlen = 0;
    int flg = 0;
    while(*s!='\0')
    {
        if(*s==cs[hlen])
        {
            if(hlen<4)
                hlen++;
            else
            {
                putchar('o');
                len++;
                hlen=0;
            }
        }
        else
            hlen=0;
        putchar(*s);
        len++;
        s++;     
    }
    putchar('\n');
    return len;
}

void main(void)
{
    printf("Hell world\n");
}
