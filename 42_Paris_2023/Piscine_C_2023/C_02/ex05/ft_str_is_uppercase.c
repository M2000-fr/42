/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:26:21 by mechard           #+#    #+#             */
/*   Updated: 2023/08/05 22:00:40 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	add;

	add = 0;
	while (str[add] != '\0' && (str[add] >= 'A' && str[add] <= 'Z'))
		add++;
	if (str[add] == '\0')
		return (1);
	else
		return (0);
}
