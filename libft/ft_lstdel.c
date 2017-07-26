/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:57:43 by lhermann          #+#    #+#             */
/*   Updated: 2016/11/23 02:58:18 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list1;
	t_list	*list2;

	if (!alst || !*alst || !del)
		return ;
	list2 = *alst;
	while (list2)
	{
		list1 = list2;
		list2 = list2->next;
		del(list1->content, list1->content_size);
		free(list1);
		list1 = NULL;
	}
	*alst = NULL;
	alst = NULL;
}
