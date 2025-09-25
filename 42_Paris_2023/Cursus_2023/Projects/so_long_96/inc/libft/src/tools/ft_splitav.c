/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitav.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:37:42 by mechard           #+#    #+#             */
/*   Updated: 2024/03/27 09:54:56 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**allocate_dest(int word_count)
{
	char	**dest;

	dest = malloc((word_count + 2) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest[0] = ft_strdup("./push_swap");
	if (!dest[0])
		return (0);
	return (dest);
}

static void	fill_dest(const char *str, char charset, char **dest,
		int word_count)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	k = 1;
	while (k < (word_count + 1))
	{
		while (str[i] == charset)
			i++;
		len = ft_next_separator(i, str, charset);
		dest[k] = ft_strncpy(i, len, str);
		if (!dest[k])
		{
			ft_dstrclean(dest, k);
			return ;
		}
		i += len;
		k++;
	}
	dest[k] = NULL;
}

char	**ft_split_argv(const char *str, char charset)
{
	int		word_count;
	char	**dest;

	word_count = count_word(str, charset);
	dest = allocate_dest(word_count);
	if (!dest)
		return (NULL);
	fill_dest(str, charset, dest, word_count);
	return (dest);
}
