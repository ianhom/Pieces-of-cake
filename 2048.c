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
                next = m;
                break;
            }
        }
        
        if(-1 != next)
        {
            if(0 == arr[i])
            {
                arr[i] = arr[next];
                arr[next] = 0;
                i = i - 1;
            }
            else if(arr[i] == arr[next])
            {
                arr[i] = arr[i]*2;
                arr[next] = 0;
            }
        }
    }
    return 0;
}
