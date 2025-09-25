#include <unistd.h>

void main(int ac, char **v)
{
    int i = 0;
    char c;

    if(ac == 2)
    {
        while(v[1][i])
        {
            if(v[1][i] == 'z')
                write(1, "a", 1);
            else if(v[1][i] == 'Z')
                write(1, "A", 1);
            else if(v[1][i] >= 'a' && v[1][i] <= 'y')
            {
                c = v[1][i] + 1;
                write(1, &c, 1);
            }
            else if(v[1][i] >= 'A' && v[1][i] <= 'Y')
            {
                c = v[1][i] + 1;
                write(1, &c, 1);
            }
            else
                write(1, &v[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}