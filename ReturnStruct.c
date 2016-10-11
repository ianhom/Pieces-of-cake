typedef struct _T
{
    uint8 u8a;
    uint8 u8b;
}T_STRUCTURE;
 
T_STRUCTURE g_tB;
 
T_STRUCTURE test1(void)
{
    T_STRUCTURE tC;
    tC.u8a = 5;
    tC.u8b = 6;
    return tC;
}
 
int main (void)
{
    g_tB = test1();    /* 返回值为结构体实体 */
    printf("g_tB.u8a = %d\n", g_tB.u8a);
    return 0；
}
