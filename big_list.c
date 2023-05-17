/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/17 14:29:38 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	s->first_step = 1;
	s->second_step = 0;
	s->final_step = 0;
	while (1)
	{
		if (s->print == 1)
		{
			usleep(250000);
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
	else if (s->second_step == 1)
	{
		sort_ha(s, ha, hb);
	}
	else if (s->final_step == 1)
		final_sort(s, ha);
}

void	count_steps(t_sort *s, t_list *ha, t_list *hb)
{
	int	counter;
	int	ha_size;
	int	hb_size;
	int	total_nbr_of_steps;
	int	rb;
	int ra;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;

	hb_size = size_list(&hb);
	ha_size = size_list(&ha);
	counter = 0;
	total_nbr_of_steps = INT_MAX;
	while (hb)
	{
		ra = steps_to(s, ha, hb->value);
		rb = counter;
		printf("Value: %lld \nSteps list a: %d\nSteps list b: %d\n", hb->value, ra, rb);
		
		if (ra > ha_size / 2 && counter <= hb_size / 2)
		{
			printf("TESTE A:  Size List hb: %d\n", hb_size);
			rra = ha_size - ra;
			rr = 0;
			ra = 0;
			rrb = 0;
			rrr = 0;
		}
		else if (ra <= ha_size / 2 && counter <= hb_size / 2)
		{
			printf("TESTE B:  Size List hb: %d\n", hb_size);
			if (ra > rb && rb == 0)
			{
				rr = 0;
			}
			else if (ra > rb && rb > 0)
			{
				rr = rb;
				ra = ra - rb;
				rb = rb - rr;
			}
			else if (ra < rb && ra == 0)
			{
				rr = 0;
				rb = rb - rr;
				ra = 0;
			}
			else if (ra < rb && ra > 0)
			{
				rr = ra;
				rb = rb - rr;
				ra = 0;
			}
			else if (ra == rb)
			{
				rr = rb;
				ra = 0;
				rb = 0;
			}
			rra = 0;
			rrb = 0;
			rrr = 0;
		}
		else if (ra > ha_size / 2 && counter > hb_size / 2)
		{
			printf("TESTE C:  Size List hb: %d\n", hb_size);
			if (ha_size - ra > hb_size - counter)
			{
				printf("A ha_size-ra:%d   hb_size-counter:%d\n", (ha_size - ra), (hb_size - counter));
				rra = ha_size - ra; // - (hb_size - counter);
				rrr = rrb;
				rrb = (hb_size - counter) - (ha_size - ra);
			}
			else if (ha_size - ra < hb_size - counter)
			{
				printf("B\n");
				rra = 0;
				rrb = (hb_size - counter) - (ha_size - ra);
				rrr = (ha_size - ra);
			}
			else if ((ha_size - ra) == (hb_size - counter))
			{
				printf("C  ha_size-ra:%d   hb_size-counter:%d\n", (ha_size - ra), (hb_size - counter));
				rrr = (ha_size - ra);
				rrb = 0;
				rra = 0;
			}
			ra = 0;
			rb = 0;
			rr = 0;
		}
		else if (ra <= ha_size / 2 && counter > hb_size / 2)
		{
			printf("TESTE D:  Size List hb: %d\n", hb_size);
			if (ra > rb && rb == 0)
			{
				rr = 0;
			}
			else if (ra > rb && rb > 0)
			{
				rrb = hb_size - counter;
			}
			else if (ra < rb && ra == 0)
			{
				rrb = hb_size - counter;
			}
			else if (ra < rb && ra > 0)
			{
				rrb = hb_size - counter;
			}
			rrr = 0;
			rra = 0;
			//ra = 0;
			rb = 0;
		}

		printf("Total Steps: %d (%d RR + %d RA + %d RB + %d RRR + %d RRA + %d RRB) \n\n", (rr + rrr + ra + rra + rb + rrb), rr, ra, rb, rrr, rra, rrb);
		
		if ((rr + rrr + ra + rra + rb + rrb) < total_nbr_of_steps)
		{
			total_nbr_of_steps = (rr + rrr + ra + rra + rb + rrb);
			s->go_rr = rr;
			s->go_ra = ra;
			s->go_rb = rb;
			s->go_rrr = rrr;
			s->go_rra = rra;
			s->go_rrb = rrb;
		}
		
		hb = hb->next;
		counter++;
	}
	printf("Less movements: %d\n", total_nbr_of_steps);
}

void	sort_ha(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	//t_list *b;

	a = *ha;
	//b = *hb;
	if (size_list(ha) == 2 && a->value > a->next->value)
		sa(ha, 0);
	
	count_steps(s, *ha, *hb);
	
	printf("SORT HA (%d RR + %d RA + %d RB + %d RRR + %d RRA + %d RRB) \n\n", s->go_rr, s->go_ra, s->go_rb, s->go_rrr, s->go_rra, s->go_rrb);
	
	while (s->go_rr)
	{
		rr(s, ha, hb, 0);
		s->go_rr--;
	}
	
	while(s->go_ra)
	{
		ra(s, ha, 0);
		s->go_ra--;
	}
	
	while(s->go_rb)
	{
		rb(s, hb, 0);
		s->go_rb--;
	}
	
	while (s->go_rrr)
	{
		rrr(s, ha, hb, 0);
		s->go_rrr--;
	}	
	
	while(s->go_rra)
	{
		rra(s, ha, 0);
		s->go_rra--;
	}
	
	while(s->go_rrb)
	{
		rrb(s, hb, 0);
		s->go_rrb--;
	}
	
	if (s->go_rr == 0 && s->go_ra == 0 && s->go_rb == 0 && s->go_rrr == 0 && s->go_rra == 0 && s->go_rrb == 0)
		pa(ha, hb);

	if (size_list(hb) == 0)
	{
		s->second_step = 0;
		s->final_step = 1;
	}
}

void	final_sort(t_sort *s, t_list **ha)
{
	while (verify_order(ha) == 0)
	{
		printf("Size ha: %d, Smallest: %d, Steps to Smallest: %d\n", size_list(ha), s->smallest, steps_to_smallest(s, *ha, s->smallest));
		if (steps_to_smallest(s, *ha, s->smallest) < size_list(ha) / 2)
			ra(s, ha, 0);
		else
			rra(s, ha, 0);
	}
}