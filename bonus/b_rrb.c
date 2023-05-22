/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rrb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:57:45 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/22 12:07:35 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrb(t_sort *sort, t_list **header)
{
	t_list	*last;
	t_list	*list;

	(void) sort;
	if (size_list(header) >= 2)
	{
		list = *header;
		while (list->next->next != NULL)
			list = list->next;
		last = list->next;
		list->next = NULL;
		last->next = *header;
		*header = last;
	}
}
