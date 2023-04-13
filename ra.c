/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:20:16 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/13 11:37:24 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_sort *sort, t_list **header, int flag)
{
	t_list	*list;
	t_list	*last;

	if (size_list(header) >= 2)
	{
		if (flag != 1)
			printf("ra\n");
		list = *header;
		*header = list->next;
		last = find_last(*header);
		last->next = list;
		list->next = NULL;
	}
	sort->last_value = find_last(header);
}
