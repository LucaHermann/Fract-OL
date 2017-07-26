/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:57:19 by lhermann          #+#    #+#             */
/*   Updated: 2016/11/22 22:48:12 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	char	d;
	int		i;

	i = ft_strlen(s);
	d = c;
	while (i >= 0 && s[i] != d)
	{
		i--;
		if (!s[i])
			return (NULL);
	}
	return ((char *)s + i);
}
