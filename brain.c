/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/20 19:39:37 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin(t_list **header_a, t_list **header_b)
{
	t_sort s;

	s.a = *header_a;
	s.b = *header_b;
	s.full_size = 1;
	s.print = 0;
	while (1)
	{
		if (s.print)
			printf("\n");
		if (*header_a)
			s.last_value_a = find_last_value(*header_a);
		if (*header_b)
			s.last_value_b = find_last_value(*header_b);
		if (!verify_order(header_a) || size_list(header_b) != 0)
			unsorted(&s, header_a, header_b);

		else if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(&s, header_a, header_b);
		s.full_size++;
		if (s.print)
		{
			pp(header_a, header_b);
			//usleep(500000);
		}
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

	if (!verify_order(ha))
	{
		if (*ha)
			s->last_value_a = find_last_value(*ha);
		if (*hb)
			s->last_value_b = find_last_value(*hb);
		if (s->print)
			printf("Segunda\n");
		//	A > B	A > C	B > C
		if (a->value > a->next->value && a->value > s->last_value_a && a->next->value > s->last_value_a)
		{
			if (s->print)
				printf("A > B	A > C	B > C\n");
			sa(ha, 0);
		}
		//	A > B	A > C	B < C
		else if (a->value > a->next->value && a->value > s->last_value_a && a->next->value < s->last_value_a)
		{
			if (s->print)
				printf("A > B	A > C	B < C\n");
			ra(s, ha, 0);
		}
		//	A > B	A < C	B < C
		else if (a->value > a->next->value && a->value < s->last_value_a && a->next->value < s->last_value_a)
		{
			if (s->print)
				printf("A > B	A < C	B < C\n");
			sa(ha, 0);
		}
		//	A < B	A < C	B > C
		else if (a->value < a->next->value && a->value < s->last_value_a && a->next->value > s->last_value_a)
		{
			if (s->print)
				printf("A < B	A < C	B > C\n");
			sa(ha, 0);
		}
		//	A < B	A > C	B > C
		else if (a->value < a->next->value && a->value > s->last_value_a && a->next->value > s->last_value_a)
		{
			if (s->print)
				printf("A < B	A > C	B > C\n");
			rra(s, ha, 0);
		}
		//	A < B	A < C	B < C
		else if (size_list(hb) < 2 && a->value < a->next->value && a->value < s->last_value_a && a->next->value < s->last_value_a)
		{
			if (s->print)
				printf("A < B	A < C	B < C\n");
			pb(ha, hb);
		}
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
	else if ((a->value > b->value && b->value < s->last_value_b && a->value == s->smallest && s->last_value_b == s->biggest)
			|| (a->value > b->value && b->value < s->last_value_b && a->value < s->last_value_b&& verify_rev_in_order(s, hb)))
		pb(ha, hb);

	else if ((a->value > b->value && b->value < s->last_value_b && a->value == s->smallest && s->last_value_b == s->biggest)
			|| (a->value > b->value && b->value < s->last_value_b && a->value > s->last_value_b&& verify_rev_in_order(s, hb)))
		rra(s, hb, 0);
	else if ((verify_order(ha) || verify_in_order(s, ha)) && verify_rev_in_order(s, hb))
	{
		
		if (s->print)
			printf("Quinta\n");
		if (s->print)
			printf("last_b: %d, smallest:%d, biggest:%d\n", s->last_value_b, s->smallest, s->biggest);
		
		if ((verify_in_order(s, ha) && verify_rev_in_order(s, hb)) || (size_list(hb) == 1 && b->value < a->value))
			pa(ha, hb);
	}
}

void	sort_list_a(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;
	t_list	*b;
	int		steps;

	a = *ha;
	b = *hb;
	steps = 0;
	find_smallest(s, *hb);
	find_biggest(s, *hb);
	if (s->print)
		printf("Sort_list_a...\n");
	if (verify_rev_in_order(s, hb))
	{

		// A > B . B > Last . Ordenado
		if (a->value > b->value && b->value > s->last_value_b && verify_rev_order(hb))
		{
			if (s->print)
				printf("A > B . B > Last . Ordenado\n");
			pb(ha, hb);
		}
		// A < Last . Ordenado
		else if (a->value < s->last_value_b && verify_rev_order(hb))
		{
			if (s->print)
				printf("A < Last . Ordenado\n");
			pb(ha, hb);
		}
		// A < B . Ordenado
		else if (a->value < b->value && a->value > b->next->value && verify_rev_order(hb))
		{
			if (s->print)
				printf("A < B . Ordenado\n");
			rb(s, hb, 0);
		}
		// A < B . B < Last . Semi Ordenado
		else if (a->value < b->value && b->value < s->last_value_b && verify_rev_in_order(s, hb))
		{
			if (s->print)
				printf("A < B . B < Last . Semi Ordenado\n");
			rb(s, hb, 0);
		}
		// A < B . B > Last . Semi Ordenado
		else if (a->value < b->value && b->value > s->last_value_b && verify_rev_in_order(s, hb))
		{
			if (s->print)
				printf("A < B . B > Last . Semi Ordenado\n");
			rb(s, hb, 0);
		}
		// A > B . A < Last . Semi Ordenado
		else if (a->value > b->value && a->value < s->last_value_b && size_list(hb))
			pb(ha, hb);

		// A > B . B < Last . Semi Ordenado
		else if (a->value > b->value && b->value < s->last_value_b && verify_rev_in_order(s, hb))
		{
			if (s->print)
				printf("Front or Rear...\n");
			if (steps_to_value(s, *hb, a->value) <= size_list(hb) / 2)
			{
				steps = steps_to_value(s, *hb, a->value);
				if (s->print)
					printf(" Steps: %d, Value: %lld, Half: %d, Total: %d\n", steps_to_value(s, *hb, a->value), a->value, size_list(hb) / 2, size_list(hb));
				while (steps-- > 0)
					rb(s, hb, 0);
			}
			else if (steps_to_value(s, *hb, a->value) > size_list(hb) / 2)
			{
				steps =  size_list(hb) - steps_to_value(s, *hb, a->value);
				if (s->print)
					printf(" Steps: %d, Value: %lld, Half: %d, Total: %d\n", steps_to_value(s, *hb, a->value), a->value, size_list(hb) / 2, size_list(hb));
				while (steps-- > 0)
					rrb(s, hb, 0);
			}
		}
	
	}
}

void	sorted(t_sort *s, t_list **header_a, t_list **header_b)
{
	(void) s;
	(void) header_b;

	//printf("sorted_empty\n");
	//if (s->print)
	printf("Total: %d", s->full_size - 1);

	if (verify_order(header_a) == 1)
		exit (0);
}
