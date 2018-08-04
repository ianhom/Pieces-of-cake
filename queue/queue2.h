#ifndef MAX_NUM_Q
#define MAX_NUM_Q      (1)
#endif

typedef struct __T_Q
{
    uint8  u8Ch;
    uint8  u8Head;
    uint8  u8Tail;
    uint8  u8MaxElm;
    uint8  u8Len;
    uint8  u8Cnt;
    uint8 *pu8Data;
}T_Q;


