#include <unistd.h>

void printnb(int nb)
{
    char c;

    if(nb >= 10)
    {
        printnb(nb / 10);
        c = nb % 10 +'0';
    }
    else 
        c = nb + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        write(1, "0\n", 2);
        return(0);
    }
    printnb(argc - 1);

    write(1, "\n", 1);
}