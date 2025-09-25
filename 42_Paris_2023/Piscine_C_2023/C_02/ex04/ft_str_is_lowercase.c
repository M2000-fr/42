/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:25:08 by mechard           #+#    #+#             */
/*   Updated: 2023/08/05 22:00:42 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	add;

	add = 0;
	while (str[add] != '\0' && (str[add] >= 'a' && str[add] <= 'z'))
		add++;
	if (str[add] == '\0')
		return (1);
	else
		return (0);
}
