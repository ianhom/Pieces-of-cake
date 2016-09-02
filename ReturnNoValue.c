#include <stdio.h>

int test2()
{
    return 5; /* Normal return */
}

int test1()
{
    return;   /* Should return an int value */
}

void main()
{
    int a = 10;
    test2();            /* Call test2 fisrt */
    a = test1();        /* Then call test1  */
    printf("%d\n",a);   /* "a" may be 5 */
}
