int UpdatData(unsigned char *arr)
{
    int i,m,next;
    for(i = 0; i < 4; i++)
    {
        next =-1;
        for(m = i+1; m < 4; m++)
        {
            if(0 != arr[m])
            {
                break;
                next = m;
            }
        }

    }
}
