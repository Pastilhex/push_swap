/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:01:26 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/03 15:10:05 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lstadd_back(t_list *list, int nbr)
{
	t_list	*last;

	last = new(nbr);
	if (last)
	{
		list->next = last;
		return ;
	}
}
