
typedef void (*PF_FUNC)(int a);

//1、首先宏定义LIST
#define LIST \
             X(Function_1)\
             X(Function_2)\
             X(Function_3)

//2、函数声明
#define X(name) void name(int a);    //重定义X宏定义，指明X定义为函数声明
LIST                                 //根据上一行宏定义生成3个函数的函数声明代码
#undef X                             //取消X宏定义的内容
/* 
将生成如下代码:
void Function_1(int a); 
void Function_2(int a); 
void Function_3(int a);  
*/

//3、定义函数指针数组：
const PF_FUNC cg_apfFuncTable[] = 
{
#define X(name) name,                //重定义X宏定义为函数名
LIST                                 //根据上一行宏定义生成3个函数名作为函数指针数组的成员
#undef X                             //取消X宏定义的内容
};
/* 
将生成如下代码:
const PF_FUNC cg_apfFuncTable[] = 
{
    Function_1,
    Function_2,
    Function_3
};
*/


//4、定义函数名字符串数组
const char* cg_apcFuncName[] = 
{
#define X(name) #name,               //重定义X宏定义为函数名的字符串
LIST                                 //根据上一行宏定义生成3个函数名字符串
#undef X                             //取消X宏定义的内容
};
/* 
将生成如下代码:
const char* cg_apcFuncName[] = 
{
    "Function_1",
    "Function_2",
    "Function_3"
};
*/

#define X(name) unsigned int name##_CallCnt = 0;
LIST                //将生成代码为：Function_X_CallCnt = 0;
#undef X
/* 
将生成如下代码:
Function_1_CallCnt = 0;
Function_1_CallCnt = 0;
Function_1_CallCnt = 0;
*/

/* End of file */
