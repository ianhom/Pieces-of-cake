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

#defien MAX_CNT_TEMP  (128)  /* Result buffer length */

char* GetStrFromBuff(char *pu8Buff, unsigned int u32Head, unsigned int u32Size)
{
    static char au8Res[MAX_CNT_TEMP];   /* Result buffer */
    unsigned int u32Index = 0;
    while(1)
    {
        au8Res[u32Index] = puc8Buff[(Head+unIndex)%u32Size];
        if((au8Res[u32Index] == '\r')&&(puc8Buff[(Head+unIndex+1)%u32Size] == '\n')&&（0 != u32Index）)
        {
            break;
        }
        u32Index++;
        if(u32Index > (2*u32Size))  /* The last try */
        {
            return NULL; /* Do NOT find it */
        }
    }
    return au8Res;
}
