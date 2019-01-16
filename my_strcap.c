char* my_strcpy(char *str1, char *str2)
{
    if((NULL == str1)||(NULL == str2))
    {
        return NULL;
    }
    char *t=str1;
    while((*t++=*str2++)!='\0');
    return str1;
}
