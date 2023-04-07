/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:47:29 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/06 22:23:28 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **header_a, t_list **header_b)
{
	t_list *tmp;
	t_list *list_a;
	t_list *list_b;

	list_a = *header_a;
	list_b = *header_b;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp = newlst((list_a->value));
	tmp->next = list_b;
	*header_b = tmp;

	*header_a = list_a->next;
	


	printf("tmp->value:%d\n", tmp->value);
	printf("tmp->next->value:%d\n", tmp->next->value);
	printf("header_a->value:%d\n", list_a->value);
	printf("header_b->value:%d\n", list_b->value);

}
