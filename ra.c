/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:20:16 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/10 18:32:59 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **header)
{
	t_list	*list;
	t_list	*last;

	printf("ra\n");
	list = *header;
	*header = list->next;
	last = find_last(*header);
	last->next = list;
	list->next = NULL;
	print_list(*header);
}
