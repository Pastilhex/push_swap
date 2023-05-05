/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/05 21:35:57 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	t_list *a;
//	t_list *b;

	a = *header_a;
//	b = *header_b;
	if (*header_a)
		s->last_value_a = find_last_value(*header_a);

	if (*header_b)
		s->last_value_b = find_last_value(*header_b);
	
	s->full_size = size_list(header_a);
	s->ha_size = s->full_size / 2;
	s->hb_size = s->full_size - s->ha_size;
	s->steps_to_last_a = steps_to(s, a, find_last_value(a));
	s->first_step = 1;
	s->second_step = 0;
	s->reverse_cycle = 0;
	s->mix_cycle = 0;
	s->x_args = size_list(header_a);
	s->y_count = 0;
	s->is_asc = 0;
	s->is_first = 0;

	while (1)
	{
		if (*header_b)
			s->last_value_b = find_last_value(*header_b);
		
		if (size_list(header_a) == 0 && size_list(header_b) != 0)
			big_unsorted(s, header_a, header_b);
		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(s, header_a, header_b);
		else if (!verify_order(header_a) || (verify_order(header_a) && size_list(header_b) != 0))
			big_unsorted(s, header_a, header_b);
		if (s->print)
			pp(header_a, header_b);

		s->full_size++;

		if (s->print)
			usleep(25000);

	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	// t_list *a;
	// t_list *b;

	// a = *ha;
	// b = *hb;


	//DIVISAO DO HA EM 2 METADES IGUAIS
	s->x_args = s->ha_size;
	while (s->x_args > 0 && s->first_step == 1)
	{
		pb(ha, hb);
	
		s->x_args--;
		s->full_size++;
		s->y_count++;
	}
	if (s->x_args <= 0 || verify_order(ha))
	{
		s->first_step = 0;
		s->second_step = 1;
	}


	// if (s->first_step == 1)
	// {
		
	// 	if (a->value > a->next->value && size_list(hb) == 0)
	// 		pb(ha, hb);
		
	// 	else if (a->value < a->next->value)
	// 		ra(s, ha, 0);
		
	// 	else if (b->value > a->value || a->value > a->next->value)
	// 		pb(ha, hb);
		
	// 	else
	// 		ra(s, ha, 0);
		
	// 	s->x_args--;
	// 	s->full_size++;
		
	// 	if (a->value == s->is_first)
	// 	{
	// 		s->first_step = 0;
	// 		s->second_step = 1;
	// 	}
	// }


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
		
		s->y_count++;
		if (s->print)
			printf("y count %d\n", s->y_count);
	}

	else if (s->reverse_cycle == 1)
	{
		reverse_sort(s, ha, hb);
	}

	else if (s->mix_cycle == 1 && verify_in_order(s, hb) == 1)
	{
		final_sort(s, ha, hb);
	}
	
	else if (s->mix_cycle == 1 && verify_in_order(s, ha) == 0)
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

void	sort_hb(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	find_biggest(s, *hb);
	find_smallest(s, *hb);

	if (s->print)
		printf("\nSort hb\n");


	if (size_list(hb) == 0)
	{
		s->mix_cycle = 0;
		s->reverse_cycle = 1;
	}
	else if (a->value > b->value && a->value > s->last_value_b && b->value == s->smallest && s->last_value_b == s->biggest)
		pb(ha, hb);

	else if (a->value < b->value && a->value < s->last_value_b && b->value == s->smallest && s->last_value_b == s->biggest)
		pb(ha, hb);

	else if (a->value > b->value && a->value > b->next->value)
		rb(s, hb, 0);

	else if (a->value > b->value && a->value < b->next->value)
		rb(s, hb, 0);

	else if (a->value < b->value && a->value > s->last_value_b)
		pb(ha, hb);

	else if (a->value < b->value && a->value < s->last_value_b)
	{
		if (steps_to_value(s, *hb, a->value) <= size_list(hb) / 2)
			rb(s, hb, 0);
		else
			rrb(s, hb, 0);
	}
	else if (verify_in_order(s, hb) && steps_to_value(s, *hb, s->smallest) <= size_list(hb) / 2)
		rb(s, hb, 0);
	else if (verify_in_order(s, hb) && steps_to_value(s, *hb, s->smallest) > size_list(hb) / 2)
		rrb(s, hb, 0);
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
	
	else if (size_list(hb) == 0 && verify_in_order(s, ha))
	{
		if (steps_to_value(s, *ha, a->value) <= size_list(ha) / 2)
			ra(s, ha, 0);
		else
			rra(s, ha, 0);
	}
	
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

void	final_sort(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	find_biggest(s, *ha);
	find_smallest(s, *ha);

	if (s->print)
		printf("\nFinal Sort\n");



	if (size_list(hb) == 0)
	{
		s->mix_cycle = 0;
		s->reverse_cycle = 1;
	}

	else if ((size_list(hb) == 1 && verify_in_order(s, ha) == 0) || (verify_order(hb) && b->value < s->smallest))
	{
		pa(ha, hb);
		s->reverse_cycle = 1;
		s->mix_cycle = 0;
	}

	else if (b->value > a->value && b->value > s->last_value_a && a->value == s->smallest && s->last_value_a == s->biggest)
		pa(ha, hb);

	else if (b->value < a->value && b->value < s->last_value_a && a->value == s->smallest && s->last_value_a == s->biggest)
		pa(ha, hb);

	else if (b->value > a->value && b->value > a->next->value)
		ra(s, ha, 0);

	else if (b->value > a->value && b->value < a->next->value)
		ra(s, ha, 0);

	else if (b->value < a->value && b->value > s->last_value_a)
		pa(ha, hb);

	else if (b->value < a->value && b->value < s->last_value_a)
	{
		if (steps_to_value(s, *ha, b->value) <= size_list(ha) / 2)
			ra(s, ha, 0);
		else
			rra(s, ha, 0);
	}
}