#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char *dest;
    int i = 0;

    while(src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * i);
    i=0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}