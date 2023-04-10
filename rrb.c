/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:57:45 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/10 20:58:29 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **header)
{
	t_list	*last;
	t_list	*list;

	printf("rrb\n");
	list = *header;
	while(list->next->next != NULL)
		list = list->next;
	last = list->next;
	list->next = NULL;
	last->next = *header;
	*header = last;
	print_list(*header);
}
