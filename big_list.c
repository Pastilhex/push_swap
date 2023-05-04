/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/04 07:39:17 by ialves-m         ###   ########.fr       */
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
	s->reverse_cycle = 0;
	s->mix_cycle = 0;


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
	int		split;

	split = s->ha_size;
	while (split > 0 && s->first_step == 1)
	{
		pb(ha, hb);
		split--;
	}
	s->first_step = 0;


	if (s->second_step == 1)
	{
		if (size_list(hb) != 0)
		{
			sort_ha(s, ha, hb);
		}
		
		else if (size_list(hb) == 0 && s->steps_to_last_a > 0)
		{
			s->first_step = 1;
			s->ha_size = s->steps_to_last_a;
		}
		
		else if (size_list(hb) == 0 && s->steps_to_last_a <= 0)
		{
			s->second_step = 0;
			s->reverse_cycle = 1;
		}
	}

	else if (s->reverse_cycle == 1)
	{
		reverse_sort(s, ha, hb);
	}

	else if (s->mix_cycle == 1)
	{
		sort_hb(s, ha, hb);
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

void	reverse_sort(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	(void) b;
	if (s->print)
		printf("Reverse Sort\n");

	if (size_list(hb) != 0 && b->value < s->last_value_a)
	{
		s->reverse_cycle = 0;
		s->mix_cycle = 1;
	}
	else if (size_list(ha) == 1 && a->value < b->value)
		sort_ha(s, ha, hb);
	else if (a->value > a->next->value && a->value > s->last_value_a && size_list(hb) == 0)
	{
		pb(ha, hb);
	}
	else if (size_list(hb) != 0 && b->value > s->last_value_a)
	{
		rra(s, ha, 0);
		pb(ha, hb);
	}
	else if (a->value < a->next->value && a->value > s->last_value_a)
		ra(s, ha, 0);
			
}

void	sort_hb(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	if (s->print)
		printf("\nSort hb\n");

	if (size_list(hb) == 0)
	{
		s->mix_cycle = 0;
		s->reverse_cycle = 1;
	}
	else if (size_list(ha) == 1 && a->value < b->value)
		pa(ha, hb);
	else if (b->value > a->value && b->value > s->last_value_a && a->value < s->last_value_a)
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