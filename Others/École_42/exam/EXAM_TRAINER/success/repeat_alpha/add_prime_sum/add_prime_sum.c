#include <unistd.h>

int	ft_atoi(char *s)
{
	int	res = 0;

	while (*s)
		res = res * 10 + *s++ - '0';
	return (res);
}

int	is_prime(int num)
{
	int	i = 2;

    //un nombre premier ne sera jamais plus petit ou égal à 1
	if (num <= 1)
		return (0);
    // num est divisible par un nombre supérieur à sa racine carrée, alors il sera également divisible par un nombre inférieur à sa racine carrée
	while (i * i <= num)
	{
        // si num est divisible par i cela signifie que num n'est pas premier, car il a un diviseur autre que 1 et lui-même
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        write(1, "0\n", 2);

	if (ac == 2)
	{
		int	nbr = ft_atoi(av[1]);
		int	sum = 0;
        int i = 0;

        while(av[1][i])
        {
            //bien vérifier qu'il n'y ai que des chiffre !!
            if(av[1][i] < '0' || av[1][i] > '9')
            {
                write(1, "0\n", 2);
                return (0);
            }
            i++;
        }

        if(nbr< 0)
        {
            write(1, "0\n", 2);
	        return (0);
        }
		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		put_nbr(sum);
        write(1, "\n", 1);
	}
	//write(1, "0\n", 2);
	return (0);
}