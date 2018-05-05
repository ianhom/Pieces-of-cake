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
    do
    {
        au8Res[u32Index] = puc8Buff[(Head+unIndex)%u32Size];
        u32Index++;
    }while(au8Res[u32Index] != '\r')
    return au8Res;
}
