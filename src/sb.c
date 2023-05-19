/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:12:05 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/18 12:53:20 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **header, int flag)
{
	int		tmp;
	t_list	*list;

	if (size_list(header) >= 2)
	{
		if (flag != 1)
			ft_putstr("sb\n");
		list = *header;
		tmp = list->value;
		list->value = list->next->value;
		list->next->value = tmp;
	}
}
