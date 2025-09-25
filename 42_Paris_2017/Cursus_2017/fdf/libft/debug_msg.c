/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 09:46:13 by tarchen           #+#    #+#             */
/*   Updated: 2017/10/21 09:13:09 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			dm(char *msg, char *f, int l)
{
	static int	fd = -1;
	char		*tmp_join;

	if (fd == -1)
	{

				fd = open("./debug_msg_file", O_CREAT|O_WRONLY|S_IRWXU);
		printf("fd = %d\n", fd);
	}
	dprintf(fd, "fonction: "C_CYAN"%s"C_RES" (at: %d) <> %s\n", f, l, msg);
}

int		main(void)
{
	dm("test", _FL_);
	return (0);
}
