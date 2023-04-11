/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:11:38 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/11 16:30:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **header, int flag)
{
	int		tmp;
	t_list	*list;

	if (size_list(header) >= 2)
	{
		if (flag != 1)
			printf("sa\n");
		list = *header;
		tmp = list->value;
		list->value = list->next->value;
		list->next->value = tmp;
	}
}