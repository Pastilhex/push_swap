/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:24:58 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin(t_list **header_a, t_list **header_b)
{
	t_sort s;

	s.a = *header_a;
	s.b = *header_b;
	s.full_size = 1;
	s.last_value = find_last_value(*header_a);
	while (1)
	{
		
		pp(header_a, header_b);
		printf("While\n");
		usleep(200000);

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


	if (verify_order(ha) && verify_rev_order(hb)
		&& b->value < a->value && a->value == s->smallest && s->last_value == s->biggest
		&& b->value < a->value && b->value > s->last_value)
		pa(ha, hb);

	else if (size_list(hb) > 1 && (!verify_rev_order(hb) || !verify_rev_in_order(s, hb)))
		sort_list_desc(s, ha, hb);

	else if (verify_order(ha) && size_list(hb) == 1 && b->value < a->value && b->value < s->last_value)
		pa(ha, hb);

	else if (verify_in_order(s, ha) && size_list(hb) == 0)
		ra(s, ha, 0);

	else if (verify_in_order(s, ha) && verify_rev_order(hb) && b->value < a->value && b->value < s->last_value && a->value == s->smallest && s->last_value == s->biggest)
		pa(ha, hb);

	else if ((verify_order(ha) || verify_in_order(s, ha)) && verify_rev_in_order(s, hb))
	{
		if (b->value > a->value && b->value < s->last_value && b->value > s->last_value_b)
			ra(s, ha, 0);

		else if (b->value < a->value && b->value < s->last_value && a->value == s->smallest && s->last_value == s->biggest)
			pa(ha, hb);

		else if (b->value > a->value && b->value < s->last_value && a->value == s->smallest && s->last_value == s->biggest)
			ra(s, ha, 0);

		else if (b->value < a->value && b->value > s->last_value)
			pa(ha, hb);

		else if (b->value < a->value && b->value < s->last_value)
			rra(s, ha, 0);
		else if ( b->value > a->value && b->value < a->next->value)
		{
			ra(s, ha, 0);
			pa(ha, hb);
			rra(s, ha, 0);
		}
	}

	else if (!verify_order(ha) || verify_in_order(s, ha))
	{
		//printf("ha not sorted\n");
		if (a->value > a->next->value && a->value > s->last_value && a->next->value > s->last_value)
			sa(ha, 0);
		else if (a->value > a->next->value && a->value > s->last_value && a->next->value < s->last_value)
			ra(s, ha, 0);
		else if (a->value > a->next->value && a->value < s->last_value && a->next->value < s->last_value)
			sa(ha, 0);
		else if (a->value < a->next->value && a->value < s->last_value && a->next->value < s->last_value)
			pb(ha, hb);
		else if (a->value < a->next->value && a->value < s->last_value && a->next->value > s->last_value)
			sa(ha, 0);
		else if (a->value < a->next->value && a->value > s->last_value && a->next->value > s->last_value)
			rra(s, ha, 0);
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

void	sort_list_desc(t_sort *s, t_list **ha,t_list **hb)
{
	//printf("Sorting desc...\n");
	t_list	*b;

	(void) *ha;
	b = *hb;
	find_smallest(s, *hb);
	find_biggest(s, *hb);
	if (b->value < b->next->value && !(b->value == s->smallest && b->next->value == s->biggest))
		sb(hb, 0);
	else if (b->value > b->next->value || verify_rev_in_order(s, hb))
		rb(s, hb, 0);
}

void	sort_list_asc(t_sort *s, t_list **ha, t_list **hb)
{
	printf("Sorting asc...\n");
	t_list	*a;

	(void) *hb;
	a = *ha;
	find_smallest(s, *hb);
	find_biggest(s, *hb);
	if (verify_in_order(s, ha))
		rra(s, ha, 0);
	else if (size_list(ha) <= 3 && ((a->value > a->next->value && a->value > s->last_value && a->next->value > s->last_value) || (a->value > a->next->value && a->value < s->last_value && a->next->value < s->last_value)))
		sa(ha, 0);
	else if (size_list(ha) <= 3 && ((a->value < a->next->value && a->value > s->last_value && a->next->value > s->last_value) || (a->value < a->next->value && a->value < s->last_value && a->next->value > s->last_value)))
		rra(s, ha, 0);
	else if (size_list(ha) > 3 && a->value > a->next->value && a->value > s->last_value && a->next->value > s->last_value)
		pb(ha, hb);

}