/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:30:30 by tarchen           #+#    #+#             */
/*   Updated: 2017/04/12 20:31:07 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char			*hex_pattern_init_bth(void)
{
	char		*hex_pattern;

	hex_pattern = try_malloc(sizeof(char) * 16, _FL_);
	hex_pattern[0] = '0';
	hex_pattern[1] = '1';
	hex_pattern[2] = '2';
	hex_pattern[3] = '3';
	hex_pattern[4] = '4';
	hex_pattern[5] = '5';
	hex_pattern[6] = '6';
	hex_pattern[7] = '7';
	hex_pattern[8] = '8';
	hex_pattern[9] = '9';
	hex_pattern[10] = 'a';
	hex_pattern[11] = 'b';
	hex_pattern[12] = 'c';
	hex_pattern[13] = 'd';
	hex_pattern[14] = 'e';
	hex_pattern[15] = 'f';
	return (hex_pattern);
}

char			*convert_bth(char *bin, char *hex_pattern)
{
	int			i;
	int			add;
	char		*hex;

	i = 0;
	hex = try_malloc(sizeof(char) * ((ft_strlen(bin) / 4) + 1), _FL_);
	hex[(ft_strlen(hex) / 4)] = '\0';
	while (bin[i])
	{
		add = 0;
		add += (bin[i] - 48) * 8;
		add += (bin[++i] - 48) * 4;
		add += (bin[++i] - 48) * 2;
		add += (bin[++i] - 48) * 1;
		i++;
		hex[(i / 4) - 1] = hex_pattern[add];
	}
	return (hex);
}

char			*ft_bintohex(char *bin_basic)
{
	char		*hex_pattern;
	char		*bin;
	char		*hex_result;
	int			i;

	i = 0;
	if (!bin_basic)
		return (NULL);
	while (bin_basic[i])
		if (bin_basic[i] != '1' && bin_basic[i] != '0')
			return (NULL);
	bin = ft_strdup(bin_basic);
	hex_pattern = hex_pattern_init_bth();
	hex_result = convert_bth(bin, hex_pattern);
	return (hex_result);
}
