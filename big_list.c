/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/09 15:02:26 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
//	t_list *a;
//	t_list *b;

//	a = *header_a;
//	b = *header_b;

	s->first_step = 1;
	s->second_step = 1;


	while (1)
	{
		if (s->print)
			pp(header_a, header_b);
		if (s->print)
			printf("\n");
		
		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(s, header_a, header_b);
	
		else if (!verify_order(header_a) || (verify_order(header_a) && size_list(header_b) != 0))
			big_unsorted(s, header_a, header_b);




		if (s->print)
			usleep(150000);

	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	if (*ha)
		s->last_value_a = find_last_value(*ha);

	if (*hb)
		s->last_value_b = find_last_value(*hb);

	if (size_list(hb) > 2)
	{
		find_smallest(s, *hb);
		find_biggest(s, *hb);
	}

	if	(size_list(hb) == 0 && s->first_step == 1)
	{
		pb(ha, hb);
		pb(ha, hb);
	}
	s->first_step = 0;

	if (s->second_step == 1)
	{
		sort_ha(s, ha, hb);
	}

}

void	sort_ha(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;

	// if (s->print)
	// 	printf("(%d steps_to(s, *hb, %lld) <= (%d)size_list(hb) / 2) && (%d steps_to(s, *hb, %lld) < %d steps_to(s, *ha, b->value))\n", steps_to_value(s, *hb, a->value), a->value, size_list(hb) / 2, steps_to(s, *hb, a->value), a->value, steps_to(s, *ha, b->value));
	

	if (size_list(ha) <= 2 && verify_rev_in_order(s, hb))
	{
		
		if ((a->value > b->value && b->value == s->biggest) || (a->value > b->value && a->value < s->last_value_b))
		{
			if (s->print)
				printf("A2\n");
			pb(ha, hb);
		}	
		else if (steps_to(s, *hb, a->value) <= size_list(hb) / 2)
		{
			if (s->print)
				printf("Inside");
			rb(s, hb, 0);
		}

		else
		{
			if (s->print)
				printf("Inside\n");
			rrb(s, hb, 0);
		}
	}
	
	else if (a->value < s->last_value_b && s->last_value_b == s->biggest && size_list(hb) == 2)
	{
		if (s->print)
			printf("A\n");
		rb(s, hb, 0);
		pb(ha, hb);
	}
	
	else if ((a->value > b->value && b->value == s->biggest) || (a->value > b->value && a->value < s->last_value_b))
	{
		if (s->print)
			printf("A2\n");
		pb(ha, hb);
	}

	else if ((a->value < b->value && a->value > b->next->value && b->value > s->last_value_b) || (a->value < b->value && b->value == s->smallest))
	{
		if (s->print)
			printf("D\n");
		rb(s, hb, 0);
		pb(ha, hb);
	}

	else if ((a->value < b->value && a->value > b->next->value) || (a->value < b->value && b->value < s->last_value_b && s->last_value_b == s->biggest && a->value > b->next->value))
	{
		if (s->print)
			printf("C\n");
		rb(s, hb, 0);
		pb(ha, hb);
	}

	else if (b->value < b->next->value && a->next->value > b->next->value)
	{
		if (s->print)
			printf("E\n");
		rr(s, ha, hb, 0);
		pb(ha, hb);
	}

	else if (size_list(hb) - steps_to(s, *hb, a->value) <= 2)
	{
		if (s->print)
			printf("F\n");
		rrb(s, hb, 0);
	}

	else if (a->next->next->value < b->next->value && a->next->next->value > b->next->next->value)
	{
		if (s->print)
			printf("G\n");
		rr(s, ha, hb, 0);
		rr(s, ha, hb, 0);
		pb(ha, hb);
	}

	else if (s->last_value_a > s->last_value_b && verify_rev_in_order(s, hb))
	{
		rrr(s, ha, hb, 0);
	}

	else if (s->last_value_a < s->last_value_b && verify_rev_in_order(s, hb))
	{
		rra(s, ha, 0);
	}

	else if ((steps_to(s, *ha, b->value) <= size_list(ha) / 2) && (steps_to(s, *ha, b->value) <= steps_to(s, *hb, a->value)))
	{
		if (s->print)
			printf("H   %d steps_to(s, *ha, b->value)\n", steps_to(s, *ha, b->value));
		ra(s, ha, 0);
	}

	else if ((steps_to(s, *ha, b->value) > size_list(ha) / 2) && (steps_to(s, *ha, b->value) <= steps_to(s, *hb, a->value)))
	{
		if (s->print)
			printf("I\n");
		rra(s, ha, 0);
	}
	
	else if ((steps_to(s, *hb, a->value) <= size_list(hb) / 2) && (steps_to(s, *hb, a->value) < steps_to(s, *ha, b->value)))
	{
		if (s->print)
			printf("J\n");
		rb(s, hb, 0);
	}

	else if ((steps_to(s, *hb, a->value) > size_list(hb) / 2) && (steps_to(s, *hb, a->value) < steps_to(s, *ha, b->value)))
	{
		if (s->print)
			printf("K\n");
		rrb(s, hb, 0);
	}
}
