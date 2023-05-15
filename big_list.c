/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/15 21:16:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	s->first_step = 1;
	s->second_step = 0;
	s->x_args = 0;
	while (1)
	{
		if (s->print == 1)
		{
			usleep(150000);
			pp(header_a, header_b);
			printf("\n");
		}

		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
				sorted(s, header_a, header_b);
		else if (!verify_order(header_a) || (verify_order(header_a) && size_list(header_b) != 0))
			big_unsorted(s, header_a, header_b);

	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	// t_list *b;

	a = *ha;
	// b = *hb;
	
	if (*ha)
		s->last_value_a = find_last_value(*ha);

	if (*hb)
		s->last_value_b = find_last_value(*hb);

	if (size_list(hb) >= 2)
	{
		find_smallest(s, *ha);
		find_biggest(s, *ha);
	}
	
	if	(s->first_step == 1)
	{
		while (size_list(ha) != 2)
			pb(ha, hb);
		if (size_list(ha) == 2)
		{
			s->first_step = 0;
			s->second_step = 1;
		}
	}
	else if (size_list(ha) == 2 && a->value > a->next->value)
		sa(ha, 0);

	else if (s->second_step == 1)
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
	if (s->print)
		count_steps(s, *ha, *hb);

	if (b->value < a->value && b->value > s->last_value_a)
		pa(ha, hb);
	
	else if (b->value > a->value && a->value < s->last_value_a)
	{
		// ra(s, ha, 0);
		pa(ha, hb);
	}
	else if ((b->value > a->value && a->value > s->last_value_a) || (b->value < a->next->value && a->next->value == s->smallest))
	{
		ra(s, ha, 0);
		pa(ha, hb);
	}

}
