/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:12:05 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/10 20:41:16 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **header)
{
	int		tmp;
	t_list	*list;

	printf("sb\n");
	list = *header;
	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
	print_list(*header);
}
