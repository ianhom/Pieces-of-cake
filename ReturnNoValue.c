#include <stdio.h>

int test2()
{
    return 5;
}

int test1()
{
    return;
}

void main()
{
    int a = 10;
    test2();
    a = test1();
    printf("%d\n",a);
}
