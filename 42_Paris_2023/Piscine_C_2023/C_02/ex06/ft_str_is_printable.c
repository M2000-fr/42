/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:29:00 by mechard           #+#    #+#             */
/*   Updated: 2023/08/05 22:00:39 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	add;

	add = 0;
	while (str[add] != '\0' && (str[add] >= ' ' && str[add] <= '~'))
		add++;
	if (str[add] == '\0')
		return (1);
	else
		return (0);
}
