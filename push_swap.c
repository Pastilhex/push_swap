/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/02 20:07:05 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_list list;


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

int	**ss(int **list)
{
	
}

int	**pa(int **list)
{
	
}

int	**pb(int **list)
{
	
}

int	**ra(int **list)
{
	
}

int	**rb(int **list)
{
	
}

int	**rr(int **list)
{
	
}

int	**rra(int **list)
{
	
}

int	**rrb(int **list)
{
	
}

int	**rrr(int **list)
{
	
}
