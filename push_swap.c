/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/11 16:32:59 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	int	n;
	int	m;
	int	flag;
	t_list	*list_a;
	t_list	**header_a;
	t_list	**header_b;

	header_a = (t_list **)malloc(sizeof(t_list*));
	header_b = (t_list **)malloc(sizeof(t_list*));
	n = 1;
	m = n + 1;
	flag = 0;
	if (argc == 2)
	{
		if (check_digit(argv[n]))
		{
			list_a = new_list(ft_atoll(argv[n]));
			*header_a = list_a;
		}
	}
	else if (argc > 2)
	{
		while (n <= argc - 2)
		{
			while (m <= argc - 1)
				if (ft_atoll(argv[n]) == ft_atoll(argv[m++]))
					display_error();
			n++;
			m = n + 1;
		}
		n = 1;
		if (check_digit(argv[n]))
		{
			list_a = new_list(ft_atoll(argv[n++]));
			*header_a = list_a;
		}
		while (n < argc)
			if (check_digit(argv[n]))
				add_back_list(header_a, ft_atoll(argv[n++]));
			else
				display_error();
	}
	else
		display_error();

	//sb(header_b);

	//pa(header_a, header_b);
	//pa(header_a, header_b);
	pa(header_a, header_b);
	pa(header_a, header_b);
//	pa(header_a, header_b);
//	pb(header_a, header_b);

	//sa(header_a);
	//sb(header_b);

	ra(header_a, flag);
	rb(header_b, flag);

	//pb(header_a, header_b);

	//ss(header_a, header_b);

	rra(header_a, flag);
	rrb(header_b, flag);
	rrr(header_a, header_b, flag);

	printf("List A\n");
	print_list(*header_a);

	printf("List B\n");
	print_list(*header_b);

	free (header_a);
	free (header_b);

	return (0);
}
