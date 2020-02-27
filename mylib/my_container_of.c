#define container_of(p,t,m) ({const typeof(((t*)0)->m) *_p=(p);(t*)((char*)_p-((size_t)&((t*)0)->m));})
#define CTNR_OF(p,t,m) ((t*)((char*)p-((size_t)&((t*)0)->m)))

//Example
typedef struct _t{
    int a;
    char b;
    int c;
}T;

void main(void)
{
    T t;
    printf("The container address is %p\n",container_of(&t.b,T,b));
}
