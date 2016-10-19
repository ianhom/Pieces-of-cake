##关于X宏的应用
- X宏（X macro）是利用宏定义来简单复制类似代码的一种运用。   
举个例子，在一个c源文件中，想建立一个函数指针数组，并建立一个包含上述函数名的字符串数组（可用于显示有哪些函数，某个函数的详细信息），如果使用传统的方法，需要如下步骤：   
```c
typedef void (*PF_FUNC)(int a);
//1、先声明函数：
void Function_1(int a); 
void Function_2(int a); 
void Function_3(int a);  

//2、定义函数指针数组：
const PF_FUNC cg_apfFuncTable[] = 
{
    Function_1,
    Function_2,
    Function_3
};

//3、定义函数名字符串数组
const char* cg_apcFuncName[] = 
{
    "Function_1",
    "Function_2",
    "Function_3"
};
```

- 从上面明显看出，Function_X被输入了3次，如果再1~3之间在增加一个函数，还要注意这3个地方对应位置不能出错。增加了工作量，也容易出错。   
为了解决这个问题，来看看X宏的解决方法：   
```c
//1、首先宏定义LIST
#define LIST \
             X(Function_1)\
             X(Function_2)\
             X(Function_3)

//2、函数声明
#define X(name) void name(int a);    //重定义X宏定义，指明X定义为函数声明
LIST                                 //根据上一行宏定义生成3个函数的函数声明代码
#undef X                             //取消X宏定义的内容

//3、定义函数指针数组：
const PF_FUNC cg_apfFuncTable[] = 
{
#define X(name) name,                //重定义X宏定义为函数名
LIST                                 //根据上一行宏定义生成3个函数名作为函数指针数组的成员
#undef X                             //取消X宏定义的内容
};

//4、定义函数名字符串数组
const char* cg_apcFuncName[] = 
{
#define X(name) #name,               //重定义X宏定义为函数名的字符串
LIST                                 //根据上一行宏定义生成3个函数名字符串
#undef X                             //取消X宏定义的内容
};
 ```
 
-由此可以看出，只需要在定义LIST时书写一次Function_X，通过对X的定义转变，来自动生成对应的代码，减少编码冗余和笔误的机会。   
有了这个基础，可以很容易追加相关代码块，例如为每个函数定义一个变量计算函数调用次数。   
```c
#define X(name) unsigned int name##_CallCnt = 0;
LIST                                 //将生成代码为：Function_X_CallCnt = 0;
#undef X
```
