/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:47:29 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/13 20:43:10 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **header_a, t_list **header_b)
{
	t_list *tmp;
	t_list *list_a;
	t_list *list_b;

	if (size_list(header_a) >= 1)
	{
		printf("pa\n");
		list_a = *header_a;
		list_b = *header_b;
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp = new_list(list_a->value);
		tmp->next = list_b;
		*header_b = tmp;
		*header_a = list_a->next;
	}
}
