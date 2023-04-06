/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/06 15:45:07 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	int	n;
	t_list	*node;
	t_list	**header_a;
	t_list	**header_b;

	header_a = (t_list **)malloc(sizeof(t_list*));
	header_b = (t_list **)malloc(sizeof(t_list*));
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

	printf("sb\n");
	sb(node);
	print_list(*header_b);

	printf("ss\n");
	ss(*header_a, *header_b);

	

	
	return (0);
}
