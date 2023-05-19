/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 10:44:40 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	s->first_step = 1;
	s->second_step = 0;
	s->final_step = 0;
	while (1)
	{
		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(s, header_a, header_b);
		else if (!verify_order(header_a)
			|| (verify_order(header_a) && size_list(header_b) != 0))
			big_unsorted(s, header_a, header_b);
	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	if (*ha)
		s->last_value_a = find_last_value(*ha);
	if (*hb)
		s->last_value_b = find_last_value(*hb);
	if (size_list(hb) >= 2)
	{
		find_smallest(s, *ha);
		find_biggest(s, *ha);
	}
	if (s->first_step == 1)
	{
		while (size_list(ha) != 2)
			pb(ha, hb);
		if (size_list(ha) == 2)
		{
			s->first_step = 0;
			s->second_step = 1;
		}
	}
	else if (s->second_step == 1)
		sort_ha(s, ha, hb);
	else if (s->final_step == 1)
		final_sort(s, ha, hb);
}

void	sort_ha(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;

	a = *ha;
	if (size_list(ha) == 2 && a->value > a->next->value)
		sa(ha, 0);
	count_steps(s, *ha, *hb);
	while (s->go_rr)
	{
		rr(s, ha, hb, 0);
		s->go_rr--;
	}
	while (s->go_ra)
	{
		ra(s, ha, 0);
		s->go_ra--;
	}
	while (s->go_rb)
	{
		rb(s, hb, 0);
		s->go_rb--;
	}
	sort_ha_continue(s, ha, hb);
}

void	sort_ha_continue(t_sort *s, t_list **ha, t_list **hb)
{
	while (s->go_rrr)
	{
		rrr(s, ha, hb, 0);
		s->go_rrr--;
	}	
	while (s->go_rra)
	{
		rra(s, ha, 0);
		s->go_rra--;
	}
	while (s->go_rrb)
	{
		rrb(s, hb, 0);
		s->go_rrb--;
	}
	if (s->go_rr == 0 && s->go_ra == 0 && s->go_rb == 0
		&& s->go_rrr == 0 && s->go_rra == 0 && s->go_rrb == 0)
		pa(ha, hb);
	if (size_list(hb) == 0)
	{
		s->second_step = 0;
		s->final_step = 1;
	}
}

void	final_sort(t_sort *s, t_list **ha, t_list **hb)
{
	int	steps;

	(void) hb;
	find_smallest(s, *ha);
	steps = steps_to_smallest(s, *ha, s->smallest);
	while (verify_order(ha) == 0)
	{
		if (steps < size_list(ha) / 2)
			ra(s, ha, 0);
		else
			rra(s, ha, 0);
	}
}
