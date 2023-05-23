/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_list_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:33:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/23 10:15:39 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	begin(t_list **header_a, t_list **header_b)
{
	t_sort	s;

	s.a = *header_a;
	s.b = *header_b;
	go_to_gnl(&s, header_a, header_b);
	if (verify_order(header_a) == 1 && size_list(header_b) == 0)
		sorted(&s, header_a, header_b);
	else if (verify_order(header_a) == 1 && size_list(header_b) == 1)
		ft_putstr("KO\n");
	else if (verify_order(header_a) == 0)
		ft_putstr("KO\n");
}

void	go_to_gnl(t_sort *sort, t_list **header_a, t_list **header_b)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		apply_move(sort, header_a, header_b, tmp);
		tmp = get_next_line(0);
	}
}

void	apply_move(t_sort *s, t_list **header_a, t_list **header_b, char *tmp)
{
	if (ft_strcmp(tmp, "pa\n"))
		pa(header_a, header_b);
	else if (ft_strcmp(tmp, "pb\n"))
		pb(header_a, header_b);
	else if (ft_strcmp(tmp, "ra\n"))
		ra(s, header_a);
	else if (ft_strcmp(tmp, "rb\n"))
		rb(s, header_b);
	else if (ft_strcmp(tmp, "rra\n"))
		rra(s, header_a);
	else if (ft_strcmp(tmp, "rrb\n"))
		rrb(s, header_b);
	else if (ft_strcmp(tmp, "rr\n"))
		rr(s, header_a, header_b);
	else if (ft_strcmp(tmp, "rrr\n"))
		rrr(s, header_a, header_b);
	else if (ft_strcmp(tmp, "sa\n"))
		sa(header_a);
	else if (ft_strcmp(tmp, "sb\n"))
		sb(header_b);
	else if (ft_strcmp(tmp, "ss\n"))
		ss(header_a, header_b);
	else
		display_error();
}

void	sorted(t_sort *s, t_list **header_a, t_list **header_b)
{
	(void) s;
	(void) header_b;
	if (verify_order(header_a) == 1)
	{
		printf("OK\n");
		free_push_swap(header_a, header_b);
		free (header_a);
		free (header_b);
		exit (0);
	}
}
