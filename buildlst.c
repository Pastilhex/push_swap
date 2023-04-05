/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/05 12:12:43 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_list	*newlst(int nbr)
{
	t_list	*var;

	var = (t_list *)malloc(sizeof(t_list));
	if (var)
	{
		var->value = nbr;
		var->next = NULL;
		return (var);
	}
	free (var);
	return (NULL);
}

void	add_front_lst(t_list **header, t_list *list, int nbr)
{
	t_list	*new;

	new = newlst(nbr);
	new->next = list;
	*header = new;
}

void	add_back_lst(t_list **header, int nbr)
{
	t_list	*new;
	t_list	*last;

	new = newlst(nbr);
	last = find_last(*header);
	last->next = new;
}

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}
