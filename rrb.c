/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:57:45 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/11 16:31:26 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **header, int flag)
{
	t_list	*last;
	t_list	*list;

	if (size_list(header)>= 2)
	{
		if (flag != 1)
			printf("rrb\n");
		list = *header;
		while(list->next->next != NULL)
			list = list->next;
		last = list->next;
		list->next = NULL;
		last->next = *header;
		*header = last;
	}
}