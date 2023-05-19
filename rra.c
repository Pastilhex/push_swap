/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:46:50 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/18 12:55:48 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_sort *sort, t_list **header, int flag)
{
	t_list	*last;
	t_list	*list;

	find_last_value(*header);
	if (size_list(header) >= 2)
	{
		if (flag != 1)
			ft_putstr("rra\n");
		list = *header;
		while (list->next->next != NULL)
			list = list->next;
		last = list->next;
		list->next = NULL;
		last->next = *header;
		sort->last_value_a = find_last_value(*header);
		*header = last;
	}
}
