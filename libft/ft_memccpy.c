/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 05:16:48 by lhermann          #+#    #+#             */
/*   Updated: 2016/11/17 02:15:58 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	unsigned char	b;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)s1;
	b = (unsigned char)c;
	src = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((*dest++ = *src++) == b)
			return (dest);
		i++;
	}
	return (NULL);
}
