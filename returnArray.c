#define MAX_NUM    5
typedef char ARRAY[MAX_NUM];
typedef struct _T
{
    ARRAY t;
}TT;

TT tt;


TT Test_fn()
{
    TT aTemp;
    int i;
    for(i = 0; i < MAX_NUM; i++)
    {
        aTemp.t[i] = i+1;
    }
    return aTemp;
}

int main (void)
{     
    unsigned int i;
    
    tt = Test_fn();
    for(i = 0; i < MAX_NUM; i++)
    {
        printf("%d\n",tt.t[i]);
    }
    return 0;
}

/* End of file */
  
