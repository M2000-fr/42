#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
    int len = abs((end - start)) + 1;
    int i = 0;
    int *result;

    result = (int*)malloc(sizeof(int) * len);

    while(i < len)
    {
        if(start < end)
        {
            result[i] = end;
            end--;
            i++;
        }
        else
        {
            result[i] = end;
            end++;
            i++;
        }
    }
    return(result);
}