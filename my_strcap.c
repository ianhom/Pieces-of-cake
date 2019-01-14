char* my_strcap(char *str1, char *str2)
{
    if((NULL == str1)||(NULL == str2))
    {
        return NULL;
    }
    int len,i;
    for(len = 0; str1[len]!='\0';len++);
    for(i = 0; i < len; i++)
    {
        str1[i] = str2[i]);
    }
    return str1;
}
