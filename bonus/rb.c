/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:20:16 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 18:23:19 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rb(t_sort *sort, t_list **header)
{
	t_list	*list;
	t_list	*last;

	(void) sort;
	if (size_list(header) >= 2)
	{
		list = *header;
		*header = list->next;
		last = find_last(*header);
		last->next = list;
		list->next = NULL;
	}
}
