char* my_strstr(char *pcstr1, char *pcstr2)
{  
    int len,i;
    for(len = 0; str1[len]!='\0';len++);
    for(i = 0; i < len; i++)
    {
        if(str1[i] != str2[i])
        {
            return NULL;
        }
    }
    return str1;
}
