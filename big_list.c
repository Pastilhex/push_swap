/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/25 19:35:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	s->start_point = size_list(header_a);
	s->big_flag = 0;
	s->x = 1;
	s->count = -1;
	while (1)
	{
		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(s, header_a, header_b);
		else if (!verify_order(header_a) || (verify_order(header_a) && size_list(header_b) != 0))
			big_unsorted(s, header_a, header_b);
		if (s->print)
			pp(header_a, header_b);
		s->full_size++;
		if (s->print)
			usleep(50000);
	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	(void) a;
	find_smallest(s, *ha);
	find_biggest(s, *ha);
	
	if (s->start_point == 0)
	{
		s->x++;
		s->start_point = size_list(ha);
	}

	if (s->big_flag == 0)
	{
		while (size_list(hb) < s->x * 3 && s->start_point >= 0)
		{
			pb(ha, hb);
			s->count++;
		}
		s->big_flag = 1;
	}
	else
	{
		if (!verify_order(hb) && s->x == 1)
		{
			     if (b->value < b->next->value && b->value < b->next->next->value && b->next->value > b->next->next->value)
				 	rrb(s, hb, 0);
			else if (b->value > b->next->value && b->value > b->next->next->value && b->next->value > b->next->next->value)
					rb(s, hb, 0);
			else if (b->value > b->next->value && b->value < b->next->next->value && b->next->value < b->next->next->value)
					sb(hb, 0);
			else if (b->value > b->next->value && b->value > b->next->next->value && b->next->value > b->next->next->value)
					rb(s, hb, 0);
			else if (b->value < b->next->value && b->value > b->next->next->value && b->next->value > b->next->next->value)
					rrb(s, hb, 0);
		}
		else if (size_list(hb) != 0)
			choose_side(s, ha, hb);

	}
}

void	choose_side(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	if (s->print)
		printf("s.count:%d\n", s->count);
	if (size_list(hb) > 2 && a->value > a->next->value && b->value > b->next->value)
		ss(ha, hb, 0);
	else if (a->value > b->value)
	{
		pa(ha, hb);
		s->count--;
	}
	else if (size_list(hb) != 0 && a->value < b->value && s->count)
	{
		ra(s, ha, 0);
		s->start_point--;
	}
	else if (size_list(hb) == 0)
		s->big_flag = 0;
	else
		pa(ha, hb);
}

// void	restart_sort(t_sort *s, t_list **ha, t_list **hb)
// {
// 	t_list *a;
// 	t_list *b;

// 	a = *ha;
// 	b = *hb;
// }
