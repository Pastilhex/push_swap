/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/18 14:47:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	else_main(int argc, char **argv, t_list **header_a)
{
	int		n;
	int		m;
	t_list	*list_a;

	n = 1;
	m = n + 1;
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
	{
		if (check_digit(argv[n]))
			add_back_list(header_a, ft_atoll(argv[n++]));
		else
			display_error();
	}
}

int	main(int argc, char	**argv)
{
	t_list	*list_a;
	t_list	**header_a;
	t_list	**header_b;

	header_a = (t_list **)malloc(sizeof(t_list *));
	header_b = (t_list **)malloc(sizeof(t_list *));
	if (argc == 2)
	{
		if (check_digit(argv[1]))
		{
			list_a = new_list(ft_atoll(argv[1]));
			*header_a = list_a;
		}
	}
	else if (argc > 2)
		else_main(argc, argv, header_a);
	else
		display_error();
	begin(header_a, header_b);
	free (header_a);
	free (header_b);
	return (0);
}
