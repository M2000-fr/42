#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
    int i = 1;
    char *ret;
    int nb = nbr;

    if(nb < 0)
    {  
        nb = -nb;
        i++;
    }
    while(nb > 9)
    {
        nb /= 10;
        i++;
    }
    ret = (char *)malloc(sizeof(char) * i + 1);
    ret[i] = '\0';
    i--;
    if(nbr == 0)
        ret[i] = '0';
    else if(nbr < 0)
    {
        ret[0] = '-';
        nbr = -nbr;
        while(i > 0)
        {
            ret[i] = nbr % 10 +'0';
            nbr /= 10;
            i--;
        }
    }
    else if(nbr > 9)
    {
        while(i >= 0)
        {
            ret[i] = nbr % 10 +'0';
            nbr /= 10;
            i--;
            
        }
    }
    else if(nbr > 0 && nbr <= 9)
        ret[i] = nbr + '0';
    
    return(ret);
}