/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/02 15:50:25 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_list(t_sort *s, t_list **header_a, t_list **header_b)
{
	t_list *a;
	t_list *b;

	(void) a;
	(void) b;
	a = *header_a;
	b = *header_b;
	s->full_size = size_list(header_a);
	s->ha_size = s->full_size / 2;
	s->hb_size = s->full_size - s->ha_size;
	s->steps_to_last_a = steps_to(s, *header_a, find_last_value(*header_a)) + 1 - s->hb_size;
	s->first_step = 1;
	s->second_step = 1;
	s->mini_cycle = 1;
	if (s->print)
	{
		printf("Full Size:%d\n", s->full_size);
		printf("ha Size:%d\n", s->ha_size);
		printf("hb Size:%d\n", s->hb_size);
		printf("Last ha value:%d\n", s->last_value_a);
		printf("Steps till last:%d\n", s->steps_to_last_a);
	}	
	while (1)
	{
		if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted(s, header_a, header_b);
		else if (!verify_order(header_a) || (verify_order(header_a) && size_list(header_b) != 0))
			big_unsorted(s, header_a, header_b);
		if (s->print)
			pp(header_a, header_b);
		s->full_size++;
		if (s->print)
			usleep(250000);
	}
}

void	big_unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;
	t_list *b;
	int		split;

	a = *ha;
	b = *hb;
	split = s->ha_size;
	
	//Divisão do array em 2 metades não ordenadas
	while (split > 0 && s->first_step == 1)
	{
		pb(ha, hb);
		split--;
	}
	s->first_step = 0;
	
	//Ordenação em conjuntos de 6 números ordenados
	if (s->second_step == 1)
	{
		if (s->mini_cycle == 1)
		{
			//Confere quantos numeros há em ha e ordena
			if (s->steps_to_last_a >= 3)
			{
				sort_three_a(s, ha, hb);
				s->cycle_a = 3;
			}
			else if (s->steps_to_last_a == 2)
			{
				if (a->value > a->next->value)
					sa(ha, 0);
				s->cycle_a = 2;
			}
			else
				s->cycle_a = 1;
			if (s->print)
				printf("Cycle A:%d\n", s->cycle_a);
			
			//Confere quantos numeros ha em hb e ordena
			if (size_list(hb) >= 3)
			{
				sort_three_b(s, ha, hb);
				s->cycle_b = 3;
			}
			else if (size_list(hb) == 2)
			{
				if (b->value > b->next->value)
					sb(hb, 0);
				s->cycle_b = 2;
			}
			else
				s->cycle_b = 1;
			if (s->print)
				printf("Cycle B:%d\n", s->cycle_b);
		
			//Desativa a ordenacao do mini cycle
			s->mini_cycle = 0;
		}			
		else if (s->cycle_a && s->cycle_b)
		{
			if (a->value < b->value)
			{
				ra(s, ha, 0);
				s->cycle_a--;
				s->steps_to_last_a--;
			}
			else if (a->value > b->value)
			{
				pa(ha, hb);
				s->cycle_b--;
				s->cycle_a++;
				s->steps_to_last_a++;
			}
		}
		else if (s->cycle_a && !s->cycle_b)
		{
			ra(s, ha, 0);
			s->cycle_a--;
			s->steps_to_last_a--;
		}
		else if (!s->cycle_a && s->cycle_b)
		{
			pa(ha, hb);
			s->cycle_b--;
			s->cycle_a++;
			s->steps_to_last_a++;
		}
		else if (!s->cycle_a && !s->cycle_b)
			s->mini_cycle = 1;

		if (s->print)
		{	
			printf("Cycle A:%d\n", s->cycle_a);
			printf("Cycle B:%d\n", s->cycle_b);
			printf("Steps to last a %d\n", s->steps_to_last_a);
		}
	}
}

void	sort_three_a(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *a;

	(void) hb;
	a = *ha;
	while (!(a->value < a->next->value && a->next->value < a->next->next->value))
	{
		if (s->print)
			printf("Sort 3 ha\n");
		if (a->value < a->next->value && a->value < a->next->next->value && a->next->value > a->next->next->value)
		{
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
		}
		else if (a->value > a->next->value && a->value < a->next->next->value && a->next->value < a->next->next->value)
		{
			sa(ha, 0);
		}
		else if ((a->value < a->next->value && a->value < a->next->next->value && a->next->value > a->next->next->value) || (a->value < a->next->value && a->value > a->next->next->value && a->next->value > a->next->next->value))
		{
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
			sa(ha, 0);
		}
		else if (a->value > a->next->value && a->value > a->next->next->value && a->next->value < a->next->next->value)
		{
			sa(ha, 0);
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
		}
		else if (a->value > a->next->value && a->value > a->next->next->value && a->next->value > a->next->next->value)
		{
			sa(ha, 0);
			ra(s, ha, 0);
			sa(ha, 0);
			rra(s, ha, 0);
			sa(ha, 0);
		}
	}
}


void	sort_three_b(t_sort *s, t_list **ha, t_list **hb)
{
	t_list *b;

	(void) ha;
	b = *hb;
	if (s->print)
		printf("Sort 3 hb\n");
	if (b->value < b->next->value && b->value < b->next->next->value && b->next->value > b->next->next->value)
		rrb(s, hb, 0);
	else if (b->value > b->next->value && b->value > b->next->next->value && b->next->value > b->next->next->value)
		rb(s, hb, 0);
	else if (b->value > b->next->value && b->value < b->next->next->value && b->next->value < b->next->next->value)
		sb(hb, 0);
	else if (b->value > b->next->value && b->value > b->next->next->value && b->next->value > b->next->next->value)
		rb(s, hb, 0);
	else if (b->value < b->next->value && b->value > b->next->next->value && b->next->value > b->next->next->value)
		rrb(s, hb, 0);
	else if (b->value > b->next->value && b->value > b->next->next->value && b->next->value < b->next->next->value)
		rb(s, hb, 0);
}