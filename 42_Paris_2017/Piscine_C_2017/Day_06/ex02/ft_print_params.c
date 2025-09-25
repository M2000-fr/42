/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:15:35 by maechard          #+#    #+#             */
/*   Updated: 2017/03/18 22:18:46 by maechard         ###   ########.fr       */
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

int		main(int argc, char *argv[])
{
	argc = 1;
	while (argv[argc] != '\0')
	{
		ft_putstr(argv[argc]);
		ft_putchar('\n');
		argc++;
	}
	return (0);
}
