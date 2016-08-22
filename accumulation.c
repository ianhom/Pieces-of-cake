/* a累加到b的c语言实现方法 */
typedef unsigned int uint32;

/* while循环累加。通过临时变量i控制累加是否结束，每次循环累加的结果保存在a中 */
uint32 test1(uint32 a, uint32 b)
{
    uint32 i = a;
    while((++i) <= b) a += i;
    return a;
}

/* for循环累加。原理同while法 */
uint32 test2(uint32 a, uint32 b)
{
    uint32 i;
    for(i = a; i <= b; i++) a += i;
    return a;
}

/* goto循环累加。原理同while法，更为接近汇编的实现形式 */
uint32 test3(uint32 a, uint32 b)
{
    uint32 i = a;
__loop:
    a += i;
    if((++i) == b)    return a;
    goto __loop;
}

/* 公式法。最好的方法，简介高效 */
uint32 test4(uint32 a, uint32 b)
{
    return ((b*b - a*a + a + b) >> 1);
}


/* 函数嵌套（不可重入），通过静态全局变量c保存累加结果，b值不停递减并嵌套该函数直到b值等于a，在依次出栈返回结果。因为有全局变量C的存在，该函数无法重入。 */
uint32 test5(uint32 a, uint32 b)
{
    static uint32 c = 0;
    c += b;
    if(a == b--)
    {
        a = c;
        c = 0;
        return a;
    }
    return test5(a,b);
}

/* 函数嵌套（可重入）。原理：a累加到b的值= 0累加到b的值 - 0累加到a的值 + a。通过0累加到s的函数嵌套可以省去全局变量的使用，此方法虽然效率较低，需要计算两次0累加到a的结果，但是因为没有全局变量的影响，该函数可以重入 */
uint32 fn(uint32 s)
{
    if(s)
    {
        return (s + fn(s-1));
    }
    return 0;
}

uint test6 (uint32 a, uint32 b)
{
    return (fn(b) - fn(a) + a);
}
