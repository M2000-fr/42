/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:09:54 by mechard           #+#    #+#             */
/*   Updated: 2023/08/05 23:44:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);
{
	int	add;

	add = 0;
	while (str[add] != '\0')
	{
		if (str[add] >= 'A' && str[add] <= 'Z')
			str[add] += 32;
		add++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	add;
	int	add2;

	add = 0;
	ft_strlowcase(str);
	while (str[add] != '\0')
	{
		add2 = add - 1;
		if (str[add] >= 'a' && str[add] <= 'z')
		{
			if (add == 0)
				str[add] -= 32;
			if (str[add2] == ' ')
				str[add] -= 32;
		}
		add++;
	}
	return (str);
}
