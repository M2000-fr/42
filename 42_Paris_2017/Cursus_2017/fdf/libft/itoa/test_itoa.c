/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 20:23:43 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/07 02:08:06 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

int			main(void)
{
	printf("%s\n", ft_itoa_b(16, LOWER, "char", 127));
	printf("%x\n", (char)127);
	printf("%s\n", ft_itoa_b(16, LOWER, "int", 128));
	printf("%x\n", (int)128);
	printf("%s\n", ft_itoa_b(16, LOWER, "char", 0));
	printf("%x\n", (char)0);
	return (0);
}
