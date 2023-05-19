/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:42:00 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 11:04:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **header_a, t_list **header_b)
{
	t_list	*tmp;
	t_list	*list_a;
	t_list	*list_b;

	if (size_list(header_b) >= 1)
	{
		ft_putstr("pa\n");
		list_a = *header_a;
		list_b = *header_b;
		tmp = new_list(list_b->value);
		tmp->next = list_a;
		*header_a = tmp;
		*header_b = list_b->next;
	}
	free (list_b);
}
