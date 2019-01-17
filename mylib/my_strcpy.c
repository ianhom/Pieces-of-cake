#define MY_STRCPY(DES,SRC) do{char *des=DES,*src=SRC;if((NULL!=des)&&(NULL!=src))while((*des++=*src++)!='\0');}while(0)

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
