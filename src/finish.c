/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:18:02 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/24 17:39:53 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_push_swap(t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*begin_a;
	t_list	*begin_b;

	list_a = *header_a;
	list_b = *header_b;
	begin_a = NULL;
	begin_b = NULL;
	if (header_a)
		free_a(list_a, begin_a);
	if (header_b)
		free_b(list_b, begin_b);
}

void	free_a(t_list *list_a, t_list *begin_a)
{
	while (list_a != NULL)
	{
		begin_a = list_a->next;
		free (list_a);
		list_a = begin_a;
	}
	if (begin_a)
		free (begin_a);
}

void	free_b(t_list *list_b, t_list *begin_b)
{
	while (list_b != NULL)
	{
		begin_b = list_b->next;
		free (list_b);
		list_b = begin_b;
	}
	if (begin_b)
		free (begin_b);
}
