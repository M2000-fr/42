#include <stdlib.h>
#include <stdio.h>

void fprime(unsigned int n)
{
    unsigned int prime;

    if (n == 1)
        printf("1");
    else
    {

        prime = 2;
        while(n > 1)
        {
            
            if(n % prime == 0)
            {
                printf("%d", prime);
                n /= prime;
                if(n > 1)
                {
                    printf("*");
                }
                prime--;
            }
            prime ++;
        }
    }
}

int main(int argc, char **argv)
{
    if(argc == 2 && argv[1] && argv[1][0] != '-')
    {
        fprime(atoi(argv[1]));
    }
    printf("\n");
}