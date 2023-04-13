/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/13 11:38:43 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_order(t_list **header_a)
{
	t_list	*list;

	list = *header_a;
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

//verifica o estado da lista a e da lista b
void	begin(t_list **header_a, t_list **header_b)
{
	t_sort sort;

	sort.list_a = *header_a;
	sort.list_b = *header_b;
	sort.last_value = NULL;
	while (verify_order(header_a) == 0 && size_list(header_b) != 0)
	{
		if (verify_order(header_a) == 1 && size_list(header_b) != 0)
			sorted_filled(&sort, header_a, header_b);
		else if (verify_order(header_a) == 0 && size_list(header_b) != 0)
			unsorted_filled(&sort, header_a, header_b);
		else if (verify_order(header_a) == 0 && size_list(header_b) == 0)
			unsorted_empty(&sort, header_a, header_b);
		else if (verify_order(header_a) == 1 && size_list(header_b) == 0)
			sorted_empty(&sort, header_a, header_b);
	}
	print_list(*header_a);
	print_list(*header_b);
}

void	sorted_filled(t_sort *sort, t_list **header_a, t_list **header_b)
{
	sort->last_value = sort->list_b->value;
	while (verify_order(header_b) == 0)
	{
		if (sort->list_b->value > sort->list_b->next->value)
			sb(header_b, 0);
		else if (sort->list_b->value < sort->list_b->next->value && sort->list_b->value < sort->last_value)
			pb(header_b, 0);
		else
			rb(header_b, 0);
	}
}

void	sorted_empty(t_sort *sort, t_list **header_a, t_list **header_b)
{

}

void	unsorted_filled(t_sort *sort, t_list **header_a, t_list **header_b)
{
	if (sort->list_a->value < sort->list_a->next->value && sort->list_a->value > sort->last_value)
	{
		ra(sort, header_a, 0);
		sort->last_value = sort->list_a->value;
	}
	else if (sort->list_a->value < sort->list_a->next->value && sort->list_a->value < sort->last_value)
	{
		if (size_list(header_b) > 1)
			if (sort->list_b->value < sort->list_b->next->value)
				pa(header_a, header_b);
			else 
			{
				sb(header_a, header_b);
				pa(header_a, header_b);
			}
		else if (size_list(header_b) == 1 && sort->list_a->value > sort->list_b->value)
		{
			pa(header_a, header_b);
			sb(header_a, header_b);
		}
		else
			pa(header_a, header_b);
	}
	else
		sa(header_a, header_b);
}

void	unsorted_empty(t_sort *sort, t_list **header_a, t_list **header_b)
{
	if (sort->list_a->value > sort->list_a->next->value && sort->list_a->next->value == sort->first_a && sort->list_a->value > sort->last_a)
		ra(sort, header_a, header_b);
	else if (sort->list_a->value > sort->list_a->next->value && sort->list_a->next->value == sort->first_a && sort->list_a->value < sort->last_a)
		pa(header_a, header_b);
	else if (sort->list_a->value < sort->list_a->next->value && sort->list_a->value > sort->last_value)
		ra(sort, header_a, 0);
	else if (sort->list_a->value < sort->list_a->next->value && sort->list_a->value < sort->last_value)
		pa(header_a, header_b);
}
