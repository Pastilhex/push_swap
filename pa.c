/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:47:29 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/06 15:53:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **header, t_list *list)
{
	t_list	*new;

	new = newlst(header->value);
	new->next = list;
    list->value = NULL;
	free(list);
	*header = new;
}
