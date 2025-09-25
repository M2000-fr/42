/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:58 by mechard           #+#    #+#             */
/*   Updated: 2023/08/07 21:38:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	add;
	unsigned int	add2;

	add = 0;
	while (to_find[add] != '\0')
		add++;
	if (add == 0)
		return (str);
	add = 0;
	while (str[add] != '\0')
	{
		add2 = 0;
		while (str[add + add2] == to_find[add2])
		{
			if (add2 == add - 1)
				return (((char *)str + add));
			add2++;
		}
		add++;
	}
	return (0);
}
