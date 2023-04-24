/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/24 19:32:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	while (1)
	{
		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(s, header_a, header_b);
		else if (!verify_order(header_a))
			big_unsorted(s, header_a, header_b);
		if (s->print)
			pp(header_a, header_b);
		usleep(50000);
	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	find_smallest(s, *ha);
	find_biggest(s, *ha);
	if (s->big_flag == 0)
	{
		while (size_list(ha) > size_list(hb))
			pb(ha, hb);
		s->big_flag = 1;
	}
	else
	{
		printf("A Smallest:%d  B Biggest:%d\n", s->smallest, s->biggest);
		if (size_list(hb) == 0 && a->value > a->next->value)
			ra(s, ha, 0);
		else if (size_list(hb) == 0 && a->value < a->next->value)
			s->big_flag = 0;
		else if (a->value == s->smallest && b->value > s->biggest)
			pa(ha, hb);
		else if (a->value < b->value)
			ra(s, ha, 0);
		else if (a->value > b->value)
			pa(ha, hb);
	}
}
