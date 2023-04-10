/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:11:38 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/10 20:40:59 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **header)
{
	int		tmp;
	t_list	*list;

	printf("sa\n");
	list = *header;
	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
	print_list(*header);
}