/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/15 14:31:14 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin(t_list **header_a, t_list **header_b)
{
	t_sort sort;

	sort.list_a = *header_a;
	sort.list_b = *header_b;
	sort.last_value = find_last_value(*header_a);
	while (1)
	{
		pp(header_a, header_b);
		usleep(500000);
		if (verify_order(header_a) == 0 && size_list(header_b) != 0)
			unsorted_filled(&sort, header_a, header_b);
		else if (verify_order(header_a) == 0 && size_list(header_b) == 0)
			unsorted_empty(&sort, header_a, header_b);
		else if ((verify_order(header_a) == 1 || (verify_in_order(&sort, header_a) == 1 && size_list(header_a) > 3)) && size_list(header_b) != 0)
			sorted_filled(&sort, header_a, header_b);
		else if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted_empty(&sort, header_a, header_b);
	}
}

void	unsorted_empty(t_sort *sort, t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *header_a;
	list_b = *header_b;
	(void) list_b;
	find_smallest(sort, *header_a);
	find_biggest(sort, *header_a);

	// A > B && A > C && B > C
	if (list_a->value > list_a->next->value && list_a->value > sort->last_value && list_a->next->value > sort->last_value)
		sa(header_a, 0);

	// A > B && A > C && B < C
	else if (list_a->value > list_a->next->value && list_a->value > sort->last_value && list_a->next->value < sort->last_value)
		ra(sort, header_a, 0);
	
	// A < B && A > C && B > C
	else if (list_a->value < list_a->next->value && list_a->value > sort->last_value && list_a->next->value > sort->last_value)
		ra(sort, header_a, 0);

	// A > B && A < C && B < C
	else if (list_a->value > list_a->next->value && list_a->value < sort->last_value && list_a->next->value < sort->last_value)
		sa(header_a, 0);
	
	// A < B && A < C && B < C
	else if (list_a->value < list_a->next->value && list_a->value < sort->last_value && list_a->next->value < sort->last_value)
		pb(header_a, header_b);

}

void	unsorted_filled(t_sort *sort, t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *header_a;
	list_b = *header_b;
	(void) list_b;

	if (list_b->value < list_a->value && list_b->value > sort->last_value)
		pa(header_a, header_b);

	// A > B && A > C && B > C
	else if (list_a->value > list_a->next->value && list_a->value > sort->last_value && list_a->next->value > sort->last_value)
		sa(header_a, 0);

	// A > B && A > C && B < C
	else if (list_a->value > list_a->next->value && list_a->value > sort->last_value && list_a->next->value < sort->last_value)
		ra(sort, header_a, 0);
	
	// A < B && A > C && B > C
	else if (list_a->value < list_a->next->value && list_a->value > sort->last_value && list_a->next->value > sort->last_value)
		ra(sort, header_a, 0);

	// A > B && A < C && B < C
	else if (list_a->value > list_a->next->value && list_a->value < sort->last_value && list_a->next->value < sort->last_value)
		sa(header_a, 0);
	
	// A < B && A < C && B < C
	else if (list_a->value < list_a->next->value && list_a->value < sort->last_value && list_a->next->value < sort->last_value)
		pb(header_a, header_b);

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
			pa(header_a, header_b);
		else
			ra(sort, header_a, 0);
	}
	if (list_b->value < list_a->value && list_b->value > sort->last_value)
		pa(header_a, header_b);
	else if (list_b->next->value < list_a->value && list_b->next->value > sort->last_value)
		sb(header_b, 0);
	else if (list_b->value < list_a->value && list_b->value < sort->last_value)
		rra(sort, header_a, 0);
	else if (list_b->value > list_a->value && list_b->value > sort->last_value)
		ra(sort, header_a, 0);
	else
		pa(header_a, header_b);
}

void	sorted_empty(t_sort *sort, t_list **header_a, t_list **header_b)
{
	(void) sort;
	(void) header_b;
	if (verify_order(header_a) == 1)
		exit (0);
}
