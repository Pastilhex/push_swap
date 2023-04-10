/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:46:50 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/10 20:58:43 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **header)
{
	t_list	*last;
	t_list	*list;

	printf("rra\n");
	list = *header;
	while(list->next->next != NULL)
		list = list->next;
	last = list->next;
	list->next = NULL;
	last->next = *header;
	*header = last;
	print_list(*header);
}
