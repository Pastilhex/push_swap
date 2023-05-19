/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 18:23:45 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*find_last(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	find_last_value(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list->value);
}

void	find_smallest(t_sort *sort, t_list *list)
{
	if (list != NULL)
		sort->smallest = INT_MAX;
	else
		sort->smallest = list->value;
	while (list != NULL)
		if (list->value > sort->smallest)
			list = list->next;
	else if (list->value < sort->smallest)
	{
		sort->smallest = list->value;
		list = list->next;
	}
}

void	find_biggest(t_sort *sort, t_list *list)
{
	if (list != NULL)
		sort->biggest = INT_MIN;
	else
		sort->biggest = list->value;
	while (list != NULL)
		if (list->value < sort->biggest)
			list = list->next;
	else if (list->value > sort->biggest)
	{
		sort->biggest = list->value;
		list = list->next;
	}
}

int	steps_to_smallest(t_sort *sort, t_list *list, int value)
{
	int	i;

	i = 0;
	(void) sort;
	while (list->next != NULL)
	{
		if (list->value > value)
		{
			i++;
			list = list->next;
		}
		else if (list->value <= value)
			return (i);
	}
	return (i);
}
