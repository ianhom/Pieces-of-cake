typedef unsigned int uint32;

uint32 test1(uint32 a, uint32 b)
{
    int i = a;
__loop:
    a += i+1;
    if((++i) == b)    return a;
    goto __loop;
}

uint32 test2(uint32 a, uint32 b)
{
    return ((b*b - a*a + a + b) >> 1);
}

uint32 fn(uint32 s)
{
    if(s)
    {
        return (s + fn(s-1));
    }
    return 0;
}

uint test3 (uint32 a, uint32 b)
{
    return (fn(b) - fn(a) + a);
}

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
    return test1(a,b);
}
