/******************************************************************************
* File       : GetStrFromBuff.c
* Function   : Get a string from a loop buffer.
* Description: To be done.          
* Version    : V1.00
* Author     : Ian
* Date       : 05th May 2018
* History    :  No.  When           Who           What
*               1    05/May/2018    Ian           Create
******************************************************************************/

#include <stdio.h>

#defien MAX_CNT_TEMP

char* GetStrFromBuff(char *pu8Buff, unsigned int u32Head, unsigned int u32Size)
{
    static char au8Res[MAX_CNT_TEMP]; 
    unsigned int u32Index = 0;
    while(1)
    {
        au8Res[u32Index] = puc8Buff[(Head+unIndex)%u32Size];
        if((au8Res[u32Index] == '\r') && (puc8Buff[(Head+unIndex)%u32Size] == '\n')||(u32Index > u32Size))
        {
            break;
        }
        u32Index++;
    }
    return au8Res;
}
