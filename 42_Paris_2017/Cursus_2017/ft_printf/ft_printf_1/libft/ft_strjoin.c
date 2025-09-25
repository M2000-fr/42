/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:46:22 by tarchen           #+#    #+#             */
/*   Updated: 2017/11/29 09:52:16 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_strnjoin_f(char **dest, char *src, int n)
{
	size_t	len;
	char	*new_str;

	if (*dest && src)
	{
		len = ft_strlen(*dest) + n;
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, *dest);
		ft_strncat(new_str, src, n);
		ft_strdel(dest);
		*dest = new_str;
	}
}

void		ft_strjoin_rf(char *src, char **dest)
{
	size_t	len;
	char	*new_str;

	if (dest && src)
	{
		len = ft_strlen(*dest) + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, src);
		ft_strcat(new_str, *dest);
		ft_strdel(dest);
		*dest = new_str;
	}
}

void		ft_strjoin_f(char **dest, char *src)
{
	size_t	len;
	char	*new_str;

	if (*dest && src)
	{
		len = ft_strlen(*dest) + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, *dest);
		ft_strcat(new_str, src);
		ft_strdel(dest);
		*dest = new_str;
	}
}

void		ft_strjoin_ff(char **dest, char *src)
{
	size_t	len;
	char	*new_str;

	if (*dest && src)
	{
		len = ft_strlen(*dest) + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, *dest);
		ft_strcat(new_str, src);
		ft_strdel(dest);
		*dest = new_str;
		ft_strdel(&src);
	}
}

char		*ft_strjoin_rrff(char *dest, char *src)
{
	size_t	len;
	char	*new_str;

	if (dest && src)
	{
		len = ft_strlen(dest) + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, dest);
		ft_strcat(new_str, src);
		ft_strdel(&dest);
		ft_strdel(&src);
		return (new_str);
	}
	return (NULL);
}

char		*ft_strjoin_rrff_b(char *dest, char *src, size_t dest_len)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_str;

	if (dest && src)
	{
		len = dest_len + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		i = 0;
		while (i < dest_len)
		{
			new_str[i] = dest[i];
			i++;
		}
		j = 0;
		while (src[j])
		{
			new_str[i] = src[j];
			j++;
			i++;
		}
		ft_strdel(&dest);
		ft_strdel(&src);
		return (new_str);
	}
	return (NULL);
}

void		ft_strjoin_ff_b(char **dest, char *src, size_t dest_len)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_str;

	if (dest && src)
	{
		len = dest_len + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		i = 0;
		while (i < dest_len)
		{
			new_str[i] = (*dest)[i];
			i++;
		}
		j = 0;
		while (src[j])
		{
			new_str[i] = src[j];
			j++;
			i++;
		}
		ft_strdel(dest);
		*dest = new_str;
		ft_strdel(&src);
	}
}

char		*ft_strjoin_rrff_bb(char *dest, char *src, size_t dest_len, size_t src_len)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_str;

	if (dest && src)
	{
		len = dest_len + src_len;
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		i = 0;
		while (i < dest_len)
		{
			new_str[i] = dest[i];
			i++;
		}
		j = 0;
		while (j < src_len)
		{
			new_str[i] = src[j];
			j++;
			i++;
		}
		ft_strdel(&dest);
		ft_strdel(&src);
		return (new_str);
	}
	return (NULL);
}

void		ft_strjoin_rff(char *src, char **dest)
{
	size_t	len;
	char	*new_str;

	if (*dest && src)
	{
		len = ft_strlen(*dest) + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, src);
		ft_strcat(new_str, *dest);
		ft_strdel(dest);
		*dest = new_str;
		ft_strdel(&src);
	}
}

void		ft_strjoin_rff_rb(char *src, char **dest, size_t dest_len)
{
	size_t	len;
	size_t	src_len;
	char	*new_str;
	size_t	i;

	if (*dest && src)
	{
		src_len = ft_strlen(src);
		len = dest_len + src_len;
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, src);
		i = 0;
		while (i < dest_len)
		{
			new_str[src_len + i] = (*dest)[i];
			i++;
		}
		ft_strdel(dest);
		*dest = new_str;
		ft_strdel(&src);
	}
}

char	*ft_strjoin(char *dest, char *src)
{
	size_t	len;
	char	*new_str;

	if (dest && src)
	{
		len = ft_strlen(dest) + ft_strlen(src);
		new_str = try_malloc(sizeof(char) * (len + 1), _FL_);
		ft_strcpy(new_str, dest);
		ft_strcat(new_str, src);
		return (new_str);
	}
	return (NULL);
}

