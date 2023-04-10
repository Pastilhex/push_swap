/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/10 18:17:52 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_list	*new_list(int nbr)
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

void	add_front_list(t_list **header, t_list *list, int nbr)
{
	t_list	*new;

	new = new_list(nbr);
	new->next = list;
	*header = new;
}

void	add_back_list(t_list **header, int nbr)
{
	t_list	*new;
	t_list	*last;

	new = new_list(nbr);
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
	printf("\n");
}

int	size_list(t_list **header)
{
	int		i;
	t_list	*list;

	i = 0;
	list = *header;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}