#include <unistd.h>

void main(int argc, char **argv)
{
    int i = 1;
    int j = 0;

    if(argc > 1)
    {
        while(i <= argc)
        {
            while(argv[i][j])
            {
                if(argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                    argv[i][j] = argv[i][j] += 32;
                if((argv[i][j] >= 'a' && argv[i][j] <= 'z') && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\t' || argv[i][j + 1] == '\n' || argv[i][j + 1] == '\0'))
                    argv[i][j] = argv[i][j] -= 32;
                write(1, &argv[i][j], 1);
                j++;
            }
            write(1, "\n", 1);
            j = 0;
            i++;
        }
    }
    else
        write(1, "\n", 1);
}