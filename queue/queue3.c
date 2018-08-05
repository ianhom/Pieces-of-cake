/* We are going to create a queue module which can save length information */

typedef struct _T_Q
{
    uint16  u16Ch;
    uint16  u16Head;
    uint16  u16Tail;
    uint16  u16MaxElm;
    uint16  u16Len;
    uint16  u16Cnt;
    uint8  *u8Data;
    uint8  *u8Len;
}T_Q;
