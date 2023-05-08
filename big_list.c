/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/08 16:08:58 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	t_list *a;
//	t_list *b;

	a = *header_a;
//	b = *header_b;

	s->first_step = 1;
	s->second_step = 1;


	while (1)
	{
		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(s, header_a, header_b);
	
		else if (!verify_order(header_a) || (verify_order(header_a) && size_list(header_b) != 0))
			big_unsorted(s, header_a, header_b);

		if (s->print)
			pp(header_a, header_b);


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
	
	if (size_list(hb) == 0 && s->first_step == 1)
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

	if (a->value < b->value && a->value < s->last_value_b && b->value > s->last_value_b)
	{
		if (s->print)
			printf("A\n");
		pb(ha, hb);
	}
	
	// else if (a->value > a->next->value && b->value < b->next->value && a->value < b->value)
	// {
	// 	if (s->print)
	// 		printf("B\n");
	// 	ss(ha,hb, 0);
	// 	pb(ha, hb);
	// }

	else if (a->value < b->value && a->value < s->last_value_b && b->value < s->last_value_b)
	{
		if (s->print)
			printf("A:%lld   B:%lld   Last A:%d   Last B:%d\n", a->value, b->value,s->last_value_a, s->last_value_b);
		
		if (s->print)
			printf("C\n");
		rb(s, hb, 0);
		pb(ha, hb);
	}

	
}
