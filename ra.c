/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:20:16 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/12 12:19:19 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_sort *sort, t_list **header, int flag)
{
	t_list	*list;
	t_list	*last;

	(void) sort;
	find_last_value(*header);
	if (size_list(header) >= 2)
	{
		if (flag != 1)
			printf("ra\n");
		list = *header;
		*header = list->next;
		sort->last_value_a = list->value;
		last = find_last(*header);
		last->next = list;
		list->next = NULL;
	}
}
