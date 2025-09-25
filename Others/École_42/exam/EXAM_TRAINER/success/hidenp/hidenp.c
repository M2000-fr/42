#include <unistd.h>

void main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int len = 0;

    if(argc == 3)
    {
        while(argv[1][len])
            len++;
        while(argv[2][j])
        {
            if(argv[1][i] == argv[2][j])
                i++;
            j++;
        }

        if(i == len)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
}