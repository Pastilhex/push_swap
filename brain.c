/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/18 19:39:41 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin(t_list **header_a, t_list **header_b)
{
	t_sort s;

	s.a = *header_a;
	s.b = *header_b;
	s.full_size = 1;
	if (*header_a)
		s.last_value_a = find_last_value(*header_a);
	if (*header_b)
		s.last_value_b = find_last_value(*header_b);
	while (1)
	{
		pp(header_a, header_b);
		printf("\n");
		usleep(150000);
		if (!verify_order(header_a) || size_list(header_b) != 0)
			unsorted(&s, header_a, header_b);

		else if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(&s, header_a, header_b);
		s.full_size++;
	}
}

void	unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;

	a = *ha;
	b = *hb;
	find_smallest(s, *ha);
	find_biggest(s, *ha);
	//printf("Unsorted...\n");

	if (size_list(hb) > 1 && (!verify_rev_order(hb) || !verify_rev_in_order(s, hb)))
		sort_list_desc(s, ha, hb);

	else if (!verify_order(ha))
	{
		if (*ha)
			s->last_value_a = find_last_value(*ha);
		if (*hb)
			s->last_value_b = find_last_value(*hb);
		printf("Segunda\n");
		//	A > B	A > C	B > C
		if (a->value > a->next->value && a->value > s->last_value_a && a->next->value > s->last_value_a)
			sa(ha, 0);

		//	A > B	A > C	B < C
		else if (a->value > a->next->value && a->value > s->last_value_a && a->next->value < s->last_value_a)
			ra(s, ha, 0);

		//	A > B	A < C	B < C
		else if (a->value > a->next->value && a->value < s->last_value_a && a->next->value < s->last_value_a)
			sa(ha, 0);

		//	A < B	A < C	B > C
		else if (a->value < a->next->value && a->value < s->last_value_a && a->next->value > s->last_value_a)
			sa(ha, 0);

		//	A < B	A > C	B > C
		else if (a->value < a->next->value && a->value > s->last_value_a && a->next->value > s->last_value_a)
			rra(s, ha, 0);

		//	A < B	A < C	B < C
		else if (a->value < a->next->value && a->value < s->last_value_a && a->next->value < s->last_value_a)
			pb(ha, hb);
	}

	else if (verify_in_order(s, ha) && size_list(hb) == 0)
	{
		//falta contar o numero de passos ate ao inicio da lista e escolher se faz ra ou rra
		printf("Terceira\n");
		ra(s, ha, 0);
	}
	else if (verify_in_order(s, ha) && verify_rev_order(hb) && b->value < a->value && b->value < s->last_value_b && a->value == s->smallest && s->last_value_b == s->biggest)
	{
		printf("Quarta\n");
		pa(ha, hb);
	}
	else if ((verify_order(ha) || verify_in_order(s, ha)) && verify_rev_in_order(s, hb))
	{
		printf("Quinta\n");
		if ((b->value > a->value && b->value < s->last_value_b && b->value > s->last_value_b) || (b->value > a->value && b->value < s->last_value_a && a->value == s->smallest && s->last_value_a == s->biggest))
			ra(s, ha, 0);
		else if ((b->value < a->value && b->value < s->last_value_b && a->value == s->smallest && s->last_value_b == s->biggest) || (b->value < a->value && b->value > s->last_value_a))
			pa(ha, hb);
		else if ( b->value > a->value && b->value < a->next->value)
		{
			ra(s, ha, 0);
			pa(ha, hb);
			rra(s, ha, 0);
		}
	}
}

void	sort_list_desc(t_sort *s, t_list **ha,t_list **hb)
{
	printf("Primeira, Sorting desc...\n");
	t_list	*a;
	t_list	*b;

	a = *ha;
	b = *hb;
	find_smallest(s, *hb);
	find_biggest(s, *hb);

	if (!verify_rev_order(hb))
	{
		printf("Biggest:%d\n", s->biggest);
		if (verify_order(ha) && s->biggest < a->value)
			pa(ha, hb);
		else if (b->value < b->next->value && !(b->value == s->smallest && b->next->value == s->biggest))
			sb(hb, 0);
		else if (b->value > b->next->value && verify_rev_in_order(s, hb))
			rrb(s, hb, 0);
		else if (b->value < b->next->value)
			rb(s, hb, 0);
	}		
}

void	sorted(t_sort *s, t_list **header_a, t_list **header_b)
{
	(void) s;
	(void) header_b;

	//printf("sorted_empty\n");
	printf("Total: %d", s->full_size);
	if (verify_order(header_a) == 1)
		exit (0);
}
