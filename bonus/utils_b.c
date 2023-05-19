/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 18:23:50 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	steps_to_value(t_sort *sort, t_list *list, int value)
{
	int	i;

	i = 0;
	(void) sort;
	while (list->next != NULL)
	{
		i++;
		if ((value > list->value && value < list->next->value)
			|| (list->value == sort->smallest
				&& list->next->value == sort->biggest)
			|| (sort->last_value_b == sort->smallest
				&& list->value == sort->biggest))
			return (i);
		else
			list = list->next;
	}
	return (i);
}

int	steps_to(t_sort *sort, t_list *list, int value)
{
	int	i;
	int	last;

	i = 0;
	last = sort->last_value_a;
	while (list->next != NULL)
	{
		find_smallest(sort, list);
		if ((value < list->value && value > last)
			|| (value < list->value && list->value == sort->smallest)
			|| (value > sort->biggest && list->value == sort->smallest))
			return (i);
		else
		{
			last = list->value;
			list = list->next;
		}
		i++;
	}
	return (i);
}

t_list	*new_list(long long nbr)
{
	t_list	*var;

	var = (t_list *)malloc(sizeof(t_list));
	if (var)
	{
		var->value = nbr;
		var->next = NULL;
		return (var);
	}
	free (var);
	return (NULL);
}

void	add_front_list(t_list **header, t_list *list, int nbr)
{
	t_list	*new;

	new = new_list(nbr);
	new->next = list;
	*header = new;
}

void	add_back_list(t_list **header, int nbr)
{
	t_list	*new;
	t_list	*last;

	new = new_list(nbr);
	last = find_last(*header);
	last->next = new;
}
