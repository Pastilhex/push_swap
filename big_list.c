/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/26 21:59:47 by ialves-m         ###   ########.fr       */
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
	s->start_point = size_list(header_a);
	s->big_flag = 0;
	s->xfactor = 1;
	s->small_sort = 1;
	s->count = 0;
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
			usleep(500000);
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


	//if (s->print)
		//printf("Small Sort:%d\n", s->small_sort);
	if (s->start_point == 0)
	{
		s->xfactor++;
		s->start_point = size_list(ha);
	}

	if (s->big_flag == 0)
	{
		while (size_list(hb) < s->xfactor * 3 && s->start_point >= 0)
		{
			pb(ha, hb);
			s->count++;
		}
		s->big_flag = 1;
		s->count *= 2;
		if (s->print)
			printf("Count:%d\n", s->count);
	}
	else if (size_list(hb) != 0)
	{
		if (size_list(hb) != 0 && !verify_order(hb) && s->xfactor == 1)
			sort_three_b(s, ha, hb);
		else if (!(a->value < a->next->value && a->next->value < a->next->next->value) && s->small_sort == 0)
		{
			sort_three_a(s, ha, hb);
			s->small_sort = 1;
		}
		else if (size_list(hb) > 2 && a->value > a->next->value && b->value > b->next->value)
			ss(ha, hb, 0);
		else if (b->value < a->value)
		{
			pa(ha, hb);
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			if (s->print)
				printf("s.count:%d\n", s->count);
		}
		else if (size_list(hb) != 0 && a->value < b->value && s->count - size_list(hb) > 0)
		{
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			if (s->print)
				printf("s.count:%d\n", s->count);
		}

		else if (size_list(hb) != 0 && s->count - size_list(hb) >= 0)
		{
			pa(ha, hb);
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			if (s->print)
				printf("s.count:%d\n", s->count);
		}
	
		else if (size_list(hb) == 0 && s->count > 0)
		{
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			if (s->print)
				printf("s.count:%d\n", s->count);	
		}
		
	}
	else if (s->count >= 0)
	{
		ra(s, ha, 0);
		s->start_point--;
		s->count--;
		if (s->print)
			printf("s.count:%d\n", s->count);	
		
	}
	else if (size_list(hb) == 0 && s->count < 0)
		s->big_flag = 0;

	if (s->count < 0)
	{
		s->big_flag = 0;
		s->count = 0;
		s->small_sort = 0;
	}

}

void	sort_three_a(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	(void) a;
	(void) b;
	a = *ha;
	b = *hb;
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
		else if (a->value < a->next->value && a->value < a->next->next->value && a->next->value > a->next->next->value)
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
	t_list *a;
	t_list *b;

	(void) a;
	(void) b;
	a = *ha;
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