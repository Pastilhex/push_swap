/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/19 12:07:55 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin(t_list **header_a, t_list **header_b)
{
	t_sort s;

	s.a = *header_a;
	s.b = *header_b;
	s.full_size = 1;
	s.print = 1;
	while (1)
	{
		if (*header_a)
			s.last_value_a = find_last_value(*header_a);
		if (*header_b)
			s.last_value_b = find_last_value(*header_b);
		if (!verify_order(header_a) || size_list(header_b) != 0)
			unsorted(&s, header_a, header_b);

		else if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(&s, header_a, header_b);
		if (s.print)
		{
			pp(header_a, header_b);
			printf("\n");
			usleep(250000);
		}
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
	
	if (s->print)
		printf("Unsorted...\n");

	if (size_list(hb) > 1 && !verify_rev_order(hb))
		sort_list_b(s, ha, hb);

	else if (!verify_order(ha))
	{
		if (*ha)
			s->last_value_a = find_last_value(*ha);
		if (*hb)
			s->last_value_b = find_last_value(*hb);
		if (s->print)
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
		else if (size_list(hb) < 2 && a->value < a->next->value && a->value < s->last_value_a && a->next->value < s->last_value_a)
			pb(ha, hb);

		//	A < B	A < C	B < C
		else if (size_list(hb) > 1 && a->value < a->next->value && a->value < s->last_value_a && a->next->value < s->last_value_a)
			sort_list_a(s, ha, hb);
	}
	else if (verify_in_order(s, ha) && size_list(hb) == 0)
	{
		//falta contar o numero de passos ate ao inicio da lista e escolher se faz ra ou rra
		if (s->print)
			printf("Terceira\n");
		ra(s, ha, 0);
	}
	else if (verify_in_order(s, ha) && verify_rev_order(hb) && b->value < a->value && b->value < s->last_value_b && a->value == s->smallest && s->last_value_b == s->biggest)
	{
		if (s->print)
			printf("Quarta\n");
		pa(ha, hb);
	}
	else if ((verify_order(ha) || verify_in_order(s, ha)) && verify_rev_in_order(s, hb))
	{
		
		if (s->print)
			printf("Quinta\n");
		if (s->print)
			printf("last_b: %d, smallest:%d, biggest:%d\n", s->last_value_b, s->smallest, s->biggest);
		
		if ((b->value > a->value && b->value < s->last_value_b && b->value > s->last_value_b) || (b->value > a->value && b->value < s->last_value_a && a->value == s->smallest && s->last_value_a == s->biggest))
			ra(s, ha, 0);
		else if ((b->value < a->value && b->value < s->last_value_b && a->value == s->smallest && s->last_value_b == s->biggest)
			  || (b->value < a->value && b->value > s->last_value_b))
			pa(ha, hb);
		else if ( b->value > a->value && b->value < a->next->value)
		{
			ra(s, ha, 0);
			pa(ha, hb);
			rra(s, ha, 0);
		}
		else if (size_list(hb) == 1 && b->value < a->value)
			pa(ha, hb);
	}
}

void	sort_list_a(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;
	t_list	*b;

	a = *ha;
	b = *hb;
	find_smallest(s, *hb);
	find_biggest(s, *hb);

	if (verify_rev_in_order(s, hb))
	{
		// > > za 
		if (a->value > b->value && verify_rev_order(hb))
			pb(ha, hb);
		
		// < < za
		else if (a->value < s->last_value_b && verify_rev_order(hb))
			pb(ha, hb);
		
		// > <
		else if (a->value > b->value && a->value < s->last_value_b)
			pb(ha, hb);

		// < < * < > * > >
		else if (steps_to_value(s, *hb, a->value) < size_list(hb) / 2)
			rb(s, hb, 0);

		else if (steps_to_value(s, *hb, a->value) > size_list(hb) / 2)
			rrb(s, hb, 0);
	}
}

void	sort_list_b(t_sort *s, t_list **ha, t_list **hb)
{
	if (s->print)
		printf("Primeira, Sorting desc...\n");

	t_list	*a;
	t_list	*b;

	a = *ha;
	b = *hb;
	find_smallest(s, *hb);
	find_biggest(s, *hb);

	if (s->print)
		printf("Biggest:%d\n", s->biggest);
	

	if (verify_rev_in_order(s, hb) && b->value != s->biggest)
		rb(s, hb, 0);
	
	else if (b->value > a->value && b->value < a->next->value)
	{
		ra(s, ha, 0);
		pa(ha, hb);
	}

	else if (b->next->value > b->value && (b->value == s->smallest && b->next->value == s->biggest))
		sb(hb, 0);

	else if (b->value < b->next->value && !verify_rev_in_order(s, hb))
		sb(hb, 0);

	else if (b->value < b->next->value && b->value < s->last_value_b)
		rrb(s, hb, 0);

	else if (verify_order(ha) && a->value < b->value)
		pa(ha, hb);

	else if (steps_to_big(s, *hb) < size_list(hb) / 2)
		rb(s, hb, 0);
	else
		rrb(s, hb, 0);

	// else if (b->value < a->value)
	// {
	// 	pa(ha, hb);
	// 	ra(s, ha, 0);
	// }
				
	
}

void	sorted(t_sort *s, t_list **header_a, t_list **header_b)
{
	(void) s;
	(void) header_b;

	//printf("sorted_empty\n");
	if (s->print)
		printf("Total: %d", s->full_size);

	if (verify_order(header_a) == 1)
		exit (0);
}
