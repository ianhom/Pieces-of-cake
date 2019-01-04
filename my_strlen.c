int my_strlen(char *s)
{
    int len;
    for(len=0;s[len]!='\0';len++);
    return len;
}
