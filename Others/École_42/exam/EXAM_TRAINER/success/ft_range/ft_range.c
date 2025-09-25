#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int len = abs((end - start)) + 1;
    int i = 0;
    int *res;

    res = (int*)malloc(sizeof(int) * len);

    while(i < len)
    {
        if(start < end)
        {
            res[i] = start;
            start++;
            i++;
        }
        else
        {
            res[i] = start;
            start--;
            i++;
        }
    }
    return(res);
}