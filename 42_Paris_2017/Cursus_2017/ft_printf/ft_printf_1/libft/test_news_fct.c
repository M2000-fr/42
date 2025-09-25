/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_news_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 09:32:52 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/13 10:14:09 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strinsert_test(char *dest, char *str, size_t n)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!dest || !str)
		return (NULL);
	tmp = try_malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(str) + 1), _FL_);
	i = -1;
	while (dest[++i] && i < n)
		tmp[i] = dest[i];
	j = -1;
	i--;
	while (str[++j])
		tmp[++i] = str[j];
	n--;
	while (dest[++n])
		tmp[++i] = dest[n];
	return (tmp);
}



int			main(int ac, char **av)
{
	char	*dest	= ft_strdup(av[1]);
	char	*str	= ft_strdup(av[2]);
	int		n		= atoi(av[3]);
	if (ac != 4)
		exit(-1);
	printf("dest: [%s], str: [%s] (n: %d) ---> [%s]\n", dest, str, n, ft_strinsert_test(dest, str, n));
	return (42);
}
