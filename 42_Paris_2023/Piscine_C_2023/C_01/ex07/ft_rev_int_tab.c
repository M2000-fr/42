/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:11:00 by mechard           #+#    #+#             */
/*   Updated: 2023/08/03 13:11:01 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		tmp;
	int		add;

	add = 0;
	size--;
	while (size >= 0 && size >= add)
	{
		tmp = tab[size];
		tab[size] = tab[add];
		tab[add] = tmp;
		add++;
		size--;
	}
}
