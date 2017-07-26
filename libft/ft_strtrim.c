/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:25:55 by lhermann          #+#    #+#             */
/*   Updated: 2016/11/23 03:53:33 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static size_t		ft_strlen_spaces(char *s)
{
	int				i;
	int				res;

	res = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		if (s[i] == '\0')
			return (0);
	}
	while (s[i] != '\0')
	{
		i++;
		res++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		res--;
	}
	return (res);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*ret;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen_spaces((char *)s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
	}
	if (!(ret = ft_strsub(s, i, len)))
		return (NULL);
	ret[len] = 0;
	return (ret);
}
