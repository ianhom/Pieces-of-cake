int UpdatData(unsigned char *arr)
{
    int i,m,next;
    /* Try to find a NON-0 number for next block */
    for(i = 0; i < 4; i++)
    {
        next =-1;
        for(m = i+1; m < 4; m++)
        {
            if(0 != arr[m])
            {
                next = m;
                break;
            }
        }
        
        /* If we find one */
        if(-1 != next)
        {   /* If the current one is 0 */
            if(0 == arr[i])
            {   /* Switch the number with next */
                arr[i] = arr[next];
                arr[next] = 0;
                i = i - 1;
            }
            /* If the current one and next one are the same */
            else if(arr[i] == arr[next])
            {
                arr[i] = arr[i]*2;
                arr[next] = 0;
            }
        }
    }
    return 0;
}
