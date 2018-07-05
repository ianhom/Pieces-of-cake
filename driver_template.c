#include "driver_template.h"

PF_CALLBACK *sg_apfCB[MAX_NUM_XXX] = {NULL};

uint32 XXX_Init(T_DRV_PAPA *ptDrvPara)
{
    uint8 u8Ch;
    /* Check if the input parameters is valid or NOT */
    if((NULL == ptDrvPara) || (ptDrvPara->u8Ch >= MAX_NUM_XXX))
    {
        return SW_ERROR;
    }
    
    u8Ch = ptDrvPara->u8Ch;
    
    /* Add callback here */
    if(NULL == sg_apfCB[u8Ch])
    {
        sg_apfCB[u8Ch] = ptDrvPara->pfCB;
    }
    
    return SW_OK;
}

uint32 XXX_Ctrl(T_DRV_PAPA *ptDrvPara)
{
    return SW_OK;
}

uint32 XXX_Read(T_DATA_OP *ptDataOp)
{
    return SW_OK;
}

uint32 XXX_Write(T_DATA_OP *ptDataOp)
{
    return SW_OK;
}

void XXX_ISR_HANDLER(void)
{

    return;
}

/* End of file */
