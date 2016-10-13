#include <stdio.h>

int main(void)
{
    unsigned int u32a = 6;
    int s32b = -10;
    int s32c;
    unsigned int u32d;
    /********************************* 1st test *******************************/
    if(u32a+s32b > 0)
    {
        printf("Positive\n");    // Do this, sum = 4294967292
    }
    else
    {
        printf("Negative\n")
    }
    
    /********************************* 2nd test *******************************/
    if(s32b+u32a > 0)
    {
        printf("Positive\n");    // Do this, sum = 4294967292
    }
    else
    {
        printf("Negative\n")
    }
    
    /********************************* 3rd test *******************************/
    s32c = u32a + s32b;
    if(s32c > 0)
    {
        printf("Positive\n");    
    }
    else
    {
        printf("Negative\n")     // Do this, sum = -4
    }
  
    /********************************* 4th test *******************************/
    u32d = v=u32a + s32b;
    if(vd > 0)
    {
        printf("Positive\n");    // Do this, sum = 4294967292
    }
    else
    {
        printf("Negative\n")
    }
    return 0;
}

/*
Result:
Positive
Positive
Negative
Positive
*/

/* End of file */
 
