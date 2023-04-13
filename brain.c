/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/13 21:54:46 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_order(t_list **header_a)
{
	t_list	*list;

	list = *header_a;
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

//verifica o estado da lista a e da lista b
void	begin(t_list **header_a, t_list **header_b)
{
	t_sort sort;

	sort.list_a = *header_a;
	sort.list_b = *header_b;
	find_smallest(&sort, *header_a);
	find_biggest(&sort, *header_a);
	sort.last_value = find_last_value(*header_a);
	while (1)
	{
		//pp(header_a, header_b);
		// usleep(500000);
		if (verify_order(header_a) == 1 && size_list(header_b) != 0)
			sorted_filled(&sort, header_a, header_b);
		else if (verify_order(header_a) == 0 && size_list(header_b) != 0)
			unsorted_filled(&sort, header_a, header_b);
		else if (verify_order(header_a) == 0 && size_list(header_b) == 0)
			unsorted_empty(&sort, header_a, header_b);
		else if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted_empty(&sort, header_a, header_b);
	}
}

void	sorted_filled(t_sort *sort, t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *header_a;
	list_b = *header_b;
	if (list_b->next == NULL)
		{
			if (list_b->value < list_a->value)
				pb(header_a, header_b);
			else
				ra(sort, header_a, 0);
		}
	else if (list_b->value < list_b->next->value)
		sb(header_b, 0);
	else if (list_b->value > list_b->next->value && list_b->value < list_a->value)
		pb(header_a, header_b);
	else
		ra(sort, header_a, 0);
}

void	sorted_empty(t_sort *sort, t_list **header_a, t_list **header_b)
{
	(void) sort;
	(void) header_b;
	if (verify_order(header_a) == 1)
	{
		// print_list(*header_a);
		// print_list(*header_b);
		exit (0);
	}
}

void	unsorted_filled(t_sort *sort, t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *header_a;
	list_b = *header_b;
	(void) list_b;
	if (list_b->value < list_a->value && list_b->value > sort->last_value)
		pb(header_a, header_b);
	// A < B && A > C
	else if (list_a->value < list_a->next->value && list_a->value > sort->last_value)
		ra(sort, header_a, 0);
	// A < B && A < C
	else if (list_a->value < list_a->next->value && list_a->value < sort->last_value)
		pa(header_a, header_b);	
	// A > B == BIG && B == SMALL
	else if (list_a->value > list_a->next->value && list_a->value == sort->biggest && list_a->next->value == sort->smallest && size_list(header_a) > 2)
		ra(sort, header_a, 0);
	// A > B
	else if (list_a->value > list_a->next->value)
		sa(header_a, 0);
}

void	unsorted_empty(t_sort *sort, t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *header_a;
	list_b = *header_b;
	(void) list_b;
	// A < B && A > C
	if (list_a->value < list_a->next->value && list_a->value > sort->last_value)
		ra(sort, header_a, 0);
	// A < B && A < C
	else if (list_a->value < list_a->next->value && list_a->value < sort->last_value)
		pa(header_a, header_b);	
	// A > B == BIG && B == SMALL
	else if (list_a->value > list_a->next->value && list_a->value == sort->biggest && list_a->next->value == sort->smallest && size_list(header_a) > 2)
		ra(sort, header_a, 0);
	// A > B
	else if (list_a->value > list_a->next->value)
		sa(header_a, 0);
}
