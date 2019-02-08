#ifndef __MY_LIB
#define __MY_LIB

// MARCO
#define _STR(x)               #x
#define STR(x)                _STR(x)

#define _EFOR0(_idx,n)        for(int _idx=0;_idx<n;_idx++)
#define _EFOR1(_idx,n)        for(int _idx=1;_idx<=n;_idx++)
#define _EFORN(_idx,a,n)      for(int _idx=a;_idx<n+a;_idx++)

#define EFOR0(_idx,n)         _EFOR0((_idx),(n))
#define EFOR1(_idx,n)         _EFOR1((_idx),(n))
#define EFORN(_idx,a,n)       _EFORN((_idx),(a),(n)) 

#define _REPEAT(num)          for(int _idx_=0;_idx_<num;_idx_++)
#define REPEAT(num)           _REPEAT((num))
#define PRTN                  do{printf("\n");}while(0)
#define _PRTNN(repeat)        do{repeat PRTN;}while(0)      
#define PRTNN(num)            _PRTNN(REPEAT(num))

#define _PRT_STR(s)           do{printf("%s\n",s);}while(0)
#define PRT_STR(s)            PRT_STR(s)

#define __PRT_ARY(a,n,type)   do{EFOR0(_idx,n){printf("%"type",",a[_idx]);}PRTN;}while(0)
#define _PRT_ARY(a,n,type)    __PRT_ARY(a,n,STR(type))
#define PRT_ARY(a,n,type)     _PRT_ARY((a),(n),type)

#define _MY_SWAP_INT(a,b)     do{int _Temp_=a;a=b;b=_Temp_;}while(0)
#define MY_SWAP_INT(a,b)      _MY_SWAP_INT((a),(b))

#define _MY_STRLEN(s,l)       do{l=0;if(0!=s)for(;s[l]!='\0';l++);}while(0)
#define MY_STRLEN(s,l)        _MY_STRLEN((s),(l))

#define _MY_STRCPY(DES,SRC)   do{char *des=DES,*src=SRC;if((NULL!=des)&&(NULL!=src))while((*des++=*src++)!='\0');}while(0)
#define MY_STRCPY(DES,SRC)    _MY_STRCPY((DES),(SRC))
// Declarations    
int my_strlen(char *a);
char* my_strcpy(char *des, char *src);
char* my_strstr(char *str1, char *str2);

#endif 
