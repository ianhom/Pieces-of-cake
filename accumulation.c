typedef unsigned int uint32;

/* while循环累加 */
uint32 test1(uint32 a, uint32 b)
{
    uint32 i = a;
    while((++i) <= b) a += i+1;
    return a;
}

/* for循环累加 */
uint32 test2(uint32 a, uint32 b)
{
    uint32 i;
    for(i = a; i <= b; i++)
    {
        a += i+1;
    }
    return a;
}

/* goto循环累加 */
uint32 test3(uint32 a, uint32 b)
{
    uint32 i = a;
__loop:
    a += i+1;
    if((++i) == b)    return a;
    goto __loop;
}

/* 公式法 */
uint32 test4(uint32 a, uint32 b)
{
    return ((b*b - a*a + a + b) >> 1);
}

/* 函数嵌套（可重入） */
uint32 fn(uint32 s)
{
    if(s)
    {
        return (s + fn(s-1));
    }
    return 0;
}

uint test5 (uint32 a, uint32 b)
{
    return (fn(b) - fn(a) + a);
}

/* 函数嵌套（不可重入） */
uint32 test6(uint32 a, uint32 b)
{
    static uint32 c = 0;
    c += b;
    if(a == b--)
    {
        a = c;
        c = 0;
        return a;
    }
    return test6(a,b);
}
