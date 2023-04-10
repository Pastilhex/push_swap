/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/10 21:02:19 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	int	n;
	t_list	*list_a;
	t_list	**header_a;
	t_list	**header_b;

	header_a = (t_list **)malloc(sizeof(t_list*));

	header_b = (t_list **)malloc(sizeof(t_list*));

	n = 1;
	if (argc == 2)
	{
		list_a = new_list(ft_atoi(argv[n]));
		*header_a = list_a;
	}
	else if (argc > 2)
	{
		list_a = new_list(ft_atoi(argv[n++]));
		*header_a = list_a;
		while (n < argc)
			add_back_list(header_a, ft_atoi(argv[n++]));
	}
	else
		return (0);

	sa(header_a);

	pa(header_a, header_b);
	pa(header_a, header_b);

	sb(header_b);

	ra(header_a);
	rb(header_b);

	pb(header_a, header_b);

	ss(header_a, header_b);

	rra(header_a);
	rrb(header_b);
	rrr(header_a, header_b);

	free (header_a);
	free (header_b);

	return (0);
}
