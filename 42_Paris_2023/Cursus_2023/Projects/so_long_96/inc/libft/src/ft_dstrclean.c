/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:24:55 by mechard           #+#    #+#             */
/*   Updated: 2024/03/26 19:25:28 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dstrclean(char **dest, int stop)
{
	int	k;

	k = 0;
	while (k < stop)
	{
		free(dest[k]);
		k++;
	}
	free(dest);
	return (NULL);
}
