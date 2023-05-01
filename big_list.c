/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/01 18:54:24 by ialves-m         ###   ########.fr       */
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
	s->count = 0;
	s->lock_ha = 0;
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
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	(void) a;
	find_smallest(s, *ha);
	find_biggest(s, *ha);

	if (s->start_point == 0)
	{
		s->xfactor++;
		s->start_point = size_list(ha);
	}

	if (s->print)
		printf("X Factor:%d\n", s->xfactor);

	if (s->big_flag == 0)
	{
		while (size_list(hb) < s->xfactor * 3 && s->start_point >= 0)
		{
			pb(ha, hb);
			s->count++;
		}
		s->big_flag = 1;
		s->count *= 2;
		// if (s->print)
		// 	printf("1 Count:%d\n", s->count);
	}

	if (size_list(hb) != 0)
	{
		if (size_list(hb) != 0 && !verify_order(hb) && s->xfactor == 1)
		{
			if (s->print)
				printf("Sort b\n");	
			sort_three_b(s, ha, hb);
		}
		else if (!verify_order_x(ha, s->xfactor * 3) && s->lock_ha == 0 && s->xfactor == 1)
		{
			if (s->print)
				printf("Sort a\n");	
			sort_three_a(s, ha, hb);
			s->lock_ha = 1;
		}
		else if (b->value < a->value)
		{
			pa(ha, hb);
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			// if (s->print)
			// 	printf("2 Count:%d\n", s->count);
		}
		else if (size_list(hb) != 0 && a->value < b->value && s->count - size_list(hb) > 0)
		{
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			// if (s->print)
			// 	printf("3 Count:%d\n", s->count);
		}

		else if (size_list(hb) != 0 && s->count - size_list(hb) >= 0)
		{
			pa(ha, hb);
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			// if (s->print)
			// 	printf("4 Count:%d\n", s->count);
		}
	
		else if (size_list(hb) == 0 && s->count > 0)
		{
			ra(s, ha, 0);
			s->start_point--;
			s->count--;
			// if (s->print)
			// 	printf("5 Count:%d\n", s->count);	
		}
		
	}
	else if (s->count > 0)
	{
		ra(s, ha, 0);
		s->start_point--;
		s->count--;
		// if (s->print)
		// 	printf("6 Count:%d\n", s->count);	
		
	}
	else if (size_list(hb) == 0 && s->count < 0)
		s->big_flag = 0;

	if (s->count <= 0)
	{
		s->big_flag = 0;
		s->count = 0;
		s->lock_ha = 0;
	}
	if (s->print)
		printf("Total Array Counter:%d\n", s->start_point);
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