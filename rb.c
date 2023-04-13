/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:20:16 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/13 15:04:47 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_sort *sort, t_list **header, int flag)
{
	t_list	*list;
	t_list	*last;

	(void) sort;
	if (size_list(header) >= 2)
	{
		if (flag != 1)
			printf("rb\n");
		list = *header;
		*header = list->next;
		last = find_last(*header);
		last->next = list;
		list->next = NULL;
	}
}
