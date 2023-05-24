/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/24 17:18:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	size_list(t_list **header)
{
	int		i;
	t_list	*list;

	i = 0;
	list = *header;
	if (list)
	{
		while (list != NULL)
		{
			i++;
			list = list->next;
		}
		return (i);
	}
	return (0);
}

int	verify_order(t_list **header)
{
	t_list	*list;

	list = *header;
	while (list != NULL)
	{
		if (list->next && list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}
