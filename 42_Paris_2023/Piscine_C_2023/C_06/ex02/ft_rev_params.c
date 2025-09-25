/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:41:26 by mechard           #+#    #+#             */
/*   Updated: 2023/08/08 21:21:10 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	add;

	add = 0;
	while (str[add] != '\0')
	{
		ft_putchar(str[add]);
		add++;
	}
}

int	main(int argc, char **argv)
{
	int	add;

	add = argc - 1;
	while (add >= 1)
	{
		ft_putstr(argv[add]);
		ft_putchar('\n');
		add--;
	}
	return (0);
}
