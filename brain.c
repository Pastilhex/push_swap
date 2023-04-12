/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/12 12:08:29 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_order(t_list **header_a)
{
	t_list	*list;

	list = *header_a;
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (1);
		list = list->next;
	}

	return (0);
}

void	begin(t_list **header_a, t_list **header_b)
{
	if (verify_order(header_a) == 0 && size_list(header_b) != 0)
		printf("Not sorted\n");
	else if (verify_order(header_a) == 1)
		printf("Not sorted\n");
	else
		printf("It's sorted\n");
	print_list(*header_a);
	print_list(*header_b);
}
