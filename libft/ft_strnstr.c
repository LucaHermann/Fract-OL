/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 03:48:41 by lhermann          #+#    #+#             */
/*   Updated: 2016/11/23 03:32:14 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 0;
	j = 0;
	len = ft_strlen(s2);
	if (!s2)
		return ((char *)s1);
	while (s1[i] != '\0' && len + i <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
