/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 01:41:05 by lhermann          #+#    #+#             */
/*   Updated: 2016/11/23 02:00:35 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char		*s;
	int			i;
	long int	m;
	char		neg;

	i = 0;
	neg = (n < 0);
	m = (long int)n;
	m = neg ? -m : m;
	while (n && ++i)
		n /= 10;
	i += (neg + !m);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	while ((--i - neg) >= 0)
	{
		s[i] = m % 10 + '0';
		m /= 10;
		s[0] = i ? '-' : s[0];
	}
	return (s);
}
