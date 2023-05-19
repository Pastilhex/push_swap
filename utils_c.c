/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/18 16:11:18 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_list(t_list **header)
{
	int		i;
	t_list	*list;

	i = 0;
	list = *header;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	verify_order(t_list **header)
{
	t_list	*list;

	list = *header;
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	verify_in_order(t_sort	*sort, t_list **header)
{
	t_list	*list;

	list = *header;
	find_smallest(sort, *header);
	find_biggest(sort, *header);
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
		{
			if (list->value == sort->biggest
				&& list->next->value == sort->smallest)
				list = list->next;
			else
				return (0);
		}
		if (list->next != NULL)
			list = list->next;
	}
	return (1);
}

int	verify_rev_order(t_list **header)
{
	t_list	*list;

	list = *header;
	while (list->next != NULL)
	{
		if (list->value < list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	verify_rev_in_order(t_sort	*sort, t_list **header)
{
	t_list	*list;

	list = *header;
	find_smallest(sort, *header);
	find_biggest(sort, *header);
	while (list->next != NULL)
	{
		if (list->value < list->next->value)
		{
			if (list->value == sort->smallest
				&& list->next->value == sort->biggest)
				list = list->next;
			else
				return (0);
		}
		if (list->next != NULL)
			list = list->next;
	}
	return (1);
}
