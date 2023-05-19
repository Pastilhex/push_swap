/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:42:00 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 18:23:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_list **header_a, t_list **header_b)
{
	t_list	*tmp;
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	if (size_list(header_b) >= 1)
	{
		list_a = *header_a;
		list_b = *header_b;
		tmp = new_list(list_b->value);
		tmp->next = list_a;
		*header_a = tmp;
		*header_b = list_b->next;
	}
	free (list_b);
}
