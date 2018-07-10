#include "driver_template.h"

PF_CALLBACK *sg_apfCB[MAX_NUM_XXX] = {NULL};

static uint32 XXX_Init(T_DRV_PAPA *ptDrvPara)
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

static uint32 XXX_Ctrl(T_DRV_PAPA *ptDrvPara)
{
    uint8 u8Ch;
    /* Check if the input parameters is valid or NOT */
    if((NULL == ptDrvPara) || (ptDrvPara->u8Ch >= MAX_NUM_XXX))
    {
        return SW_ERROR;
    }
    return SW_OK;
}

static uint32 XXX_Read(T_DATA_OP *ptDataOp)
{
    uint8 u8Ch;
    /* Check if the input parameters is valid or NOT */
    if((NULL == ptDataOp) || (ptDataOp->u8Ch >= MAX_NUM_XXX))
    {
        return SW_ERROR;
    }
    return SW_OK;
}

static uint32 XXX_Write(T_DATA_OP *ptDataOp)
{
    uint8 u8Ch;
    /* Check if the input parameters is valid or NOT */
    if((NULL == ptDataOp) || (ptDataOp->u8Ch >= MAX_NUM_XXX))
    {
        return SW_ERROR;
    }
    return SW_OK;
}

uint32 XXX_Reg(T_DEV_PARA *ptDevPara)
{
    T_DEV tDev;
    /* Check if the input parameters is valid or NOT */
    if((NULL == ptDevPara) || (ptDevPara->u8Ch >= MAX_NUM_XXX))
    {
        return SW_ERROR;
    }
    
    tDev.u8Ch        = ptDevPara->u8Ch;
    tDev.tOp.pfInit  = XXX_Init;
    tDev.tOp.pfCtrl  = XXX_Ctrl;
    tDev.tOp.pfRead  = XXX_Read;
    tDev.tOp.pfWrite = XXX_Write;
    Dev_Regster(&tDev);
    return SW_OK;
}

void XXX_ISR_HANDLER(void)
{
    T_CB_PARA tCBPara;
    uint8 u8Ch; /* Try to get the channel */
    /* Get the type of interrupting */
    
    /* Call the callback function if it is available */
    if(sg_apfCB[u8Ch])
    {
        sg_apfCB[u8Ch](&tCBPara);
    }
    return;
}

/* End of file */
