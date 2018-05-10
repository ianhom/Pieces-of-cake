char* my_strstr(char *pcstr1, char *pcstr2, unsigned int u32Len)
{
    unsigned int  u32Index = 0;
    char         *pRet = NULL;
    
    /* If the length is 0 which means use lib strstr */
    if(0 == u32Len)
    {
        return strstr(pcstr1,pcstr2);
    }
    else
    {
        /* To be done */
    }
    return pRet;
}
