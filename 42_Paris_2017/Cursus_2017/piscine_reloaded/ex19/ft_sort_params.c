/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 18:44:03 by maechard          #+#    #+#             */
/*   Updated: 2017/04/10 19:01:09 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		adresse;

	adresse = 0;
	while (str[adresse] != '\0')
	{
		ft_putchar(str[adresse]);
		adresse++;
	}
}

void	ft_is_sort(char **str, int a)
{
	char	*tmp;
	int		tmp_b;
	int		b;
	int		c;

	c = 0;
	tmp_b = 0;
	while (tmp_b < a)
	{
		b = tmp_b + 1;
		while (b < a)
		{
			while (str[b][c] == str[tmp_b][c])
				c++;
			if (str[b][c] < str[tmp_b][c])
			{
				tmp = str[b];
				str[b] = str[tmp_b];
				str[tmp_b] = tmp;
			}
			c = 0;
			b++;
		}
		tmp_b++;
	}
}

int		main(int ac, char **av)
{
	ac = 1;
	while (av[ac - 1] != '\0')
	{
		ft_is_sort(av, ac);
		ac++;
	}
	ac = 1;
	while (av[ac] != '\0')
	{
		ft_putstr(av[ac]);
		ft_putchar('\n');
		ac++;
	}
	return (0);
}
