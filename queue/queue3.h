
typedef struct _T_Q
{
    uint16  u16Ch;
    uint16  u16Head;
    uint16  u16Tail;
    uint16  u16MaxElm;
    uint16  u16Len;
    uint16  u16Cnt;
    uint8  *pu8Data;
    uint8  *pu8Len;
}T_Q;

#ifndef MAX_NUM_Q
#define MAX_NUM_Q        (10)
#endif
