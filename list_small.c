/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 10:54:24 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin(t_list **header_a, t_list **header_b)
{
	t_sort	s;

	s.a = *header_a;
	s.b = *header_b;
	while (1)
	{
		if (*header_a)
			s.last_value_a = find_last_value(*header_a);
		if (*header_b)
			s.last_value_b = find_last_value(*header_b);
		if (size_list(header_a) <= 5)
		{
			if (!verify_order(header_a) || size_list(header_b) != 0)
				unsorted(&s, header_a, header_b);
			else if (verify_order(header_a) == 1 && size_list(header_b) == 0)
				sorted(&s, header_a, header_b);
		}
		else
			big_list(&s, header_a, header_b);
	}
}

void	sort_list_a(t_sort *s, t_list **ha, t_list **hb)
{
	find_smallest(s, *hb);
	find_biggest(s, *hb);
	if (verify_rev_in_order(s, hb))
		sort_list_aa(s, ha, hb);
}

void	sort_list_aa(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;
	t_list	*b;

	a = *ha;
	b = *hb;
	if (a->value > b->value
		&& b->value > s->last_value_b && verify_rev_order(hb))
		pb(ha, hb);
	else if (a->value < s->last_value_b && verify_rev_order(hb))
		pb(ha, hb);
	else if (a->value < b->value
		&& a->value > b->next->value && verify_rev_order(hb))
		rb(s, hb, 0);
	else if (a->value < b->value
		&& b->value < s->last_value_b && verify_rev_in_order(s, hb))
		rb(s, hb, 0);
	else if (a->value < b->value
		&& b->value > s->last_value_b && verify_rev_in_order(s, hb))
		rb(s, hb, 0);
	else if (a->value > b->value
		&& a->value < s->last_value_b && size_list(hb))
		pb(ha, hb);
	else if (a->value > b->value
		&& b->value < s->last_value_b && verify_rev_in_order(s, hb))
		sort_list_aaa(s, ha, hb);
}

void	sort_list_aaa(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;
	int		steps;

	a = *ha;
	steps = 0;
	if (steps_to_value(s, *hb, a->value) <= size_list(hb) / 2)
	{
		steps = steps_to_value(s, *hb, a->value);
		while (steps-- > 0)
			rb(s, hb, 0);
	}
	else if (steps_to_value(s, *hb, a->value) > size_list(hb) / 2)
	{
		steps = size_list(hb) - steps_to_value(s, *hb, a->value);
		while (steps-- > 0)
			rrb(s, hb, 0);
	}
}

void	sorted(t_sort *s, t_list **header_a, t_list **header_b)
{
	(void) s;
	(void) header_b;
	if (verify_order(header_a) == 1)
	{
		free_push_swap(header_a, header_b);
		free (header_a);
		free (header_b);
		exit (0);
	}
}
