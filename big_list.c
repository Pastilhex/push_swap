/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/03 23:09:25 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	t_list *a;
//	t_list *b;

	a = *header_a;
//	b = *header_b;
	s->full_size = size_list(header_a);
	s->ha_size = s->full_size / 2;
	s->hb_size = s->full_size - s->ha_size;
	s->steps_to_last_a = steps_to(s, a, find_last_value(a));
	s->first_step = 1;
	s->second_step = 1;
	s->mini_cycle = 1;


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
			usleep(250000);
	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	int		split;

	split = s->ha_size;
	while (split > 0 && s->first_step == 1)
	{
		pb(ha, hb);
		split--;
	}
	s->first_step = 0;

	printf("steps to last a %d\n", s->steps_to_last_a);

	if (s->second_step == 1)
	{
		if (s->mini_cycle == 1 && size_list(hb) != 0)
		{
			sort_ha(s, ha, hb);
		}
		
		if (size_list(hb) == 0 && s->steps_to_last_a > 0)
		{
			s->first_run = 1;
			s->ha_size = s->steps_to_last_a;
		}
	}
}

void	sort_ha(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	if (s->print)
		printf("\nSort ha\n");

	if (b->value > a->value && b->value > s->last_value_a && a->value < s->last_value_a)
	{
		pa(ha, hb);
	}
	else if (b->value < a->value && b->value < s->last_value_a && a->value < s->last_value_a)
	{
		pa(ha, hb);
	}
	else if (b->value > a->value && b->value < s->last_value_a && a->value < s->last_value_a)
	{
		ra(s, ha, 0);
		s->steps_to_last_a--;
	}
	else if (b->value < a->value && b->value > s->last_value_a && a->value > s->last_value_a)
	{
		pa(ha, hb);
	}
	else if (b->value < a->value && b->value < s->last_value_a && a->value > s->last_value_a)
	{
		ra(s, ha, 0);
		s->steps_to_last_a--;
	}
	else if (b->value > a->value && b->value > s->last_value_a && a->value > s->last_value_a)
	{
		ra(s, ha, 0);
		s->steps_to_last_a--;
	}
}