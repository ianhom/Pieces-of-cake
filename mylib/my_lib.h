#ifndef __MY_LIB
#ifdef __MY_LIB

//MARCO
#define _STR(x)          #x
#define STR(x)           _STR(X)


#define PRTN             do{printf("\n");}while(0)
#define _PRTNN(repeat)   do{repeat PRTN;}while(0)      
#define PRTNN(num)       _PRTNN(REPEAT(num))

int my_strlen(char *a);
char* my_strcpy(char *des, char *src);
char* my_strstr(char *str1, char *str2);

#endif 
