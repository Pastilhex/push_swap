/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/06 22:32:56 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	int	n;
	t_list	*node;
	t_list	*nulo;
	t_list	**header_a;
	t_list	**header_b;


	header_a = (t_list **)malloc(sizeof(t_list*));
	if (header_a)
		printf("header_a\n");

	header_b = (t_list **)malloc(sizeof(t_list*));
	if (header_b)
		printf("header_b\n");

	nulo = (t_list *)malloc(sizeof(t_list));
	*header_b = nulo;

	n = 1;
	if (argc == 2)
	{
		node = newlst(ft_atoi(argv[n]));
		*header_a = node;
	}
	else if (argc > 2)
	{
		node = newlst(ft_atoi(argv[n++]));
		*header_a = node;
		while (n < argc)
			add_back_lst(header_a, ft_atoi(argv[n++]));
	}
	else
		return (0);

	printf("Input List\n");
	print_list(*header_a);


	printf("sa\n");
	sa(node);
	print_list(*header_a);

	// printf("sb\n");
	// sb(node);
	// print_list(*header_b);

	printf("pa\n");
	pa(header_a, header_b);
	print_list(*header_a);
	print_list(*header_b);

	

	free (header_a);
	free (header_b);

	return (0);
}
