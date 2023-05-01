/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/01 22:36:47 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	t_list *a;
	t_list *b;

	(void) a;
	(void) b;
	a = *header_a;
	b = *header_b;
	s->full_size = size_list(header_a);
	s->ha_size = s->full_size / 2;
	s->hb_size = s->full_size - s->ha_size;
	s->last_value_a = find_last_value(*header_a);
	if (s->print)
	{
		printf("Full Size:%d\n", s->full_size);
		printf("ha Size:%d\n", s->ha_size);
		printf("hb Size:%d\n", s->hb_size);
		printf("Last ha value:%d\n", s->last_value_a);
		printf("Steps till last:%d\n", steps_to(s, *header_a, s->last_value_a));
	}	
	s->first_step = 1;
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
	//t_list *a;
	t_list *b;
	int		split;

	//a = *ha;
	b = *hb;
	find_smallest(s, *ha);
	find_biggest(s, *ha);
	split = s->ha_size;
	
	//Divisão do array em 2 metades não ordenadas
	while (split > 0 && s->first_step == 1)
	{
		pb(ha, hb);
		split--;
	}
	s->first_step = 0;
	
	//Ordenação em conjuntos de 6 números
	if (s->second_step == 1)
	{
		while (size_list(hb) != 0)
		{
			//if ()
			
			if (size_list(hb) >= 3)
				sort_three_b(s, ha, hb);
			else if (size_list(hb) == 2)
				if (b->value > b->next->value)
					sb(hb, 0);
		}
	}
}

void	sort_three_a(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;

	(void) hb;
	a = *ha;
	while (!(a->value < a->next->value && a->next->value < a->next->next->value))
	{
		if (a->value < a->next->value && a->value < a->next->next->value && a->next->value > a->next->next->value)
		{
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
		}
		else if (a->value > a->next->value && a->value < a->next->next->value && a->next->value < a->next->next->value)
		{
			sa(ha, 0);
		}
		else if ((a->value < a->next->value && a->value < a->next->next->value && a->next->value > a->next->next->value) || (a->value < a->next->value && a->value > a->next->next->value && a->next->value > a->next->next->value))
		{
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
			sa(ha, 0);
		}
		else if (a->value > a->next->value && a->value > a->next->next->value && a->next->value < a->next->next->value)
		{
			sa(ha, 0);
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
		}
		else if (a->value > a->next->value && a->value > a->next->next->value && a->next->value > a->next->next->value)
		{
			sa(ha, 0);
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
			sa(ha, 0);
		}
	}
}


void	sort_three_b(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *b;

	(void) ha;
	b = *hb;
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
	else if (b->value > b->next->value && b->value > b->next->next->value && b->next->value < b->next->next->value)
		rb(s, hb, 0);
}