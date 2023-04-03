/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:56:13 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/03 15:10:02 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lstadd_front(t_list *list, int nbr)
{
	t_list	*new;

	new = lstnew(nbr);
	if (list)
		new->next = list;
}
