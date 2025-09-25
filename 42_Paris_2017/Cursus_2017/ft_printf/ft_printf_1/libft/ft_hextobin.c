/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:41:40 by tarchen           #+#    #+#             */
/*   Updated: 2017/04/12 21:06:07 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char			*hex_pattern_init_htb(void)
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

char			**bin_pattern_init_htb(void)
{
	char		**bin_pattern;

	bin_pattern = try_malloc(sizeof(char*) * 16, _FL_);
	bin_pattern[0] = ft_strdup("0000");
	bin_pattern[1] = ft_strdup("0001");
	bin_pattern[2] = ft_strdup("0010");
	bin_pattern[3] = ft_strdup("0011");
	bin_pattern[4] = ft_strdup("0100");
	bin_pattern[5] = ft_strdup("0101");
	bin_pattern[6] = ft_strdup("0110");
	bin_pattern[7] = ft_strdup("0111");
	bin_pattern[8] = ft_strdup("1000");
	bin_pattern[9] = ft_strdup("1001");
	bin_pattern[10] = ft_strdup("1010");
	bin_pattern[11] = ft_strdup("1011");
	bin_pattern[12] = ft_strdup("1100");
	bin_pattern[13] = ft_strdup("1101");
	bin_pattern[14] = ft_strdup("1110");
	bin_pattern[15] = ft_strdup("1111");
	return (bin_pattern);
}

char			*convert_htb(char *hex_pattern, char **bin_pattern, char *hex)
{
	int			i;
	int			j;
	int			k;
	char		*bin_result;

	i = -1;
	bin_result = try_malloc(sizeof(char) * ((ft_strlen(hex) * 4) + 1), _FL_);
	k = -1;
	while (hex[++i])
	{
		if (hex[i] == ' ')
			continue ;
		j = -1;
		while (++j < 16 && hex_pattern[j] != hex[i])
			if (hex[i] >= 65 && hex[i] <= 90)
				hex[i] += 32;
		if (j == 16)
			return (NULL);
		bin_result[++k] = bin_pattern[j][0];
		bin_result[++k] = bin_pattern[j][1];
		bin_result[++k] = bin_pattern[j][2];
		bin_result[++k] = bin_pattern[j][3];
	}
	return (bin_result);
}

char			*ft_hextobin(char *hex_basic)
{
	char		**bin_pattern;
	char		*hex_pattern;
	char		*bin_result;
	char		*hex;
	int			i;

	i = 0;
	if (!hex_basic)
		return (NULL);
	while (hex_basic[i])
		if (hex_basic[i] != '1' && hex_basic[i] != '0')
			return (NULL);
	hex = ft_strdup(hex_basic);
	bin_pattern = bin_pattern_init_htb();
	hex_pattern = hex_pattern_init_htb();
	bin_result = try_malloc(sizeof(char*) * ft_strlen(hex), _FL_);
	bin_result = convert_htb(hex_pattern, bin_pattern, hex);
	return (bin_result);
}
