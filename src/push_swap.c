/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 19:00:38 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_list	**header_a;
	t_list	**header_b;
	int	n;

	n = 1;
	if (argc == 1)
		exit (0);
	while (n < argc)
	{
		if (check_digit(argv[n]) != 1)
			display_error();
		n++;
	}
	header_a = (t_list **)malloc(sizeof(t_list *));
	header_b = (t_list **)malloc(sizeof(t_list *));
	*header_b = NULL;
	more_main(argc, argv, header_a, header_b);
	return (0);
}

void	more_main(int argc, char**argv, t_list **header_a, t_list **header_b)
{
	t_list	*list_a;

	if (argc == 2)
	{
		list_a = new_list(ft_atoll(argv[1]));
		*header_a = list_a;
	}
	else if (argc > 2)
	{
		else_main(argc, argv, header_a, header_b);
		begin(header_a, header_b);
	}
	else
		display_error();
}

void	else_main(int argc, char **argv, t_list **header_a, t_list **header_b)
{
	int		n;
	int		m;
	t_list	*list_a;

	(void) header_b;
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
	list_a = new_list(ft_atoll(argv[n++]));
	*header_a = list_a;
	while (n < argc)
		if (check_digit(argv[n]))
			add_back_list(header_a, ft_atoll(argv[n++]));
		else
			display_error();
}
