#include <stdio.h>
int main(int argc, char **argv)
{
    for(int i = 0; i < argc; i++)
    {
        printf("The No.%d parameter is %s\n",i,argv[i]);
    }
    return 0;
}
