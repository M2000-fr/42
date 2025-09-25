#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char *res;
    char buffer[999999] = {0};
    char character;
    int i = 0;

    if((fd < 0) || (BUFFER_SIZE <= 0))
        return(NULL);
    while((read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;
        if(character == '\n')
            break;
    }
    if(!buffer[0])
        return(NULL);
    res = malloc(i + 1);
    i = 0;
    while(buffer[i])
    {
        res[i] = buffer[i];
        i++;
    }
    res[i] = '\0';
    return(res);
}
