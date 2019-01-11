#include <stdio.h>
int main(int argc, char **argv)
{
    printf("The first parameter is the Path and name of this program \"%s\"\n",argv[0]);
    for(int i = 0; i < argc; i++)
    {
        printf("The No.%d parameter is %s\n",i,argv[i]);
    }
    return 0;
}
