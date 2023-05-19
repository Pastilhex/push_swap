/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:18:02 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 18:22:57 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_push_swap(t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*begin;

	(void) header_b;
	list_a = *header_a;
	while (list_a->next != NULL)
	{
		begin = list_a->next;
		free (list_a);
		list_a = begin;
	}
	free (begin);
}
