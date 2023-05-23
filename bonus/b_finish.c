/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_finish.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:18:02 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/23 14:56:20 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_push_swap(t_list **header_a, t_list **header_b)
{
	t_list	*list_a;
	t_list	*begin_a;

	(void) header_b;
	list_a = *header_a;
	while (list_a != NULL)
	{
		begin_a = list_a->next;
		free (list_a);
		list_a = begin_a;
	}
	free (begin_a);
}

void	error_not_numeric(t_list **header_a, t_list **header_b)
{
	ft_putstr("Error\n");
	free (header_a);
	free (header_b);
	exit(0);
}

void	display_error(t_list **header_a, t_list **header_b)
{
	ft_putstr("Error\n");
	(void) header_a;
	(void) header_b;
	exit(0);
}

void	error_no_move(t_list **header_a, t_list **header_b, char *tmp)
{
	ft_putstr("Error\n");
	free_push_swap(header_a, header_b);
	free (header_a);
	free (header_b);
	free (tmp);
	exit(0);
}
