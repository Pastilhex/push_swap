/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/03 17:31:30 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else
		return (NULL);
}

void	addlst(t_list *list, int nbr)
{
	t_list	*new;

	new = newlst(nbr);
	list->next = new;
}

void	printlst(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->value);
		list = list->next;
	}	
}
int	main(int argc, char** argv)
{
	(void) argc;
	(void) argv;
	t_list	*list;

	list = newlst(5);
	list = newlst(10);
	list->next = list;
	addlst(list, 10);
	addlst(list, 15);
	addlst(list, 20);

	printlst(list);
}

void	sa(t_list* list)
{
	int	tmp;

	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
}

void	sb(t_list *list)
{
	int	tmp;

	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
}
