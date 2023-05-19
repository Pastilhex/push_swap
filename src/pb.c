/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:47:29 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 13:45:17 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **header_a, t_list **header_b)
{
	t_list	*tmp;
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	if (size_list(header_a) >= 1)
	{
		ft_putstr("pb\n");
		list_a = *header_a;
		list_b = *header_b;
		tmp = new_list(list_a->value);
		tmp->next = list_b;
		*header_b = tmp;
		*header_a = list_a->next;
	}
	free (list_a);
}
