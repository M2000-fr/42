/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:45:33 by maechard          #+#    #+#             */
/*   Updated: 2017/03/19 11:29:04 by maechard         ###   ########.fr       */
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
	argc = 0;
	ft_putstr(argv[0]);
	ft_putchar('\n');
	return (0);
}
