/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:09:41 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/18 15:43:44 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_steps(t_sort *s, t_list *ha, t_list *hb)
{
	s->hb_size = size_list(&hb);
	s->ha_size = size_list(&ha);
	s->counter = 0;
	s->total_nbr_of_steps = INT_MAX;
	while (hb)
	{
		s->ra = steps_to(s, ha, hb->value);
		s->rb = s->counter;
		if (s->ra > s->ha_size / 2 && s->counter <= s->hb_size / 2)
			count_one(s);
		else if (s->ra <= s->ha_size / 2 && s->counter <= s->hb_size / 2)
		{
			count_two(s);
			count_three(s);
		}
		else if (s->ra > s->ha_size / 2 && s->counter > s->hb_size / 2)
			count_four(s);
		else if (s->ra <= s->ha_size / 2 && s->counter > s->hb_size / 2)
			count_five(s);
		if ((s->rr + s->rrr + s->ra + s->rra + s->rb + s->rrb)
			< s->total_nbr_of_steps)
			count_final_steps(s);
		hb = hb->next;
		s->counter++;
	}
}

void	count_final_steps(t_sort *s)
{
	s->total_nbr_of_steps = (s->rr + s->rrr + s->ra + s->rra + s->rb + s->rrb);
	s->go_rr = s->rr;
	s->go_ra = s->ra;
	s->go_rb = s->rb;
	s->go_rrr = s->rrr;
	s->go_rra = s->rra;
	s->go_rrb = s->rrb;
}
