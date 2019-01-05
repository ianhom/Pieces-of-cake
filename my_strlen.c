int my_strlen(char *s)
{
    if(NULL == s)
    {
        return 0;
    }
    int len;
    for(len=0;s[len]!='\0';len++);
    return len;
}
