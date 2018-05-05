#include <stdio.h>
char* GetStrFromBuff(char *pu8Buff, unsigned int u32Head, unsigned int u32Size)
{
    static char au8Res[128]; 
    unsigned int u32Index = 0;
    do
    {
        au8Res[u32Index] = puc8Buff[(Head+unIndex)%u32Size];
        u32Index++;
    }while(au8Res[u32Index] != '\r')
    return au8Res;
}
