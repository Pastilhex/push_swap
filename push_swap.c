/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/05 14:00:18 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	int	n;
	t_list	*node;
	t_list	**header;

	header = (t_list **)malloc(sizeof(t_list*));
	n = 1;
	if (argc == 2)
	{
		node = newlst(ft_atoi(argv[n]));
		*header = node;
	}
	else if (argc > 2)
	{
		node = newlst(ft_atoi(argv[n++]));
		*header = node;
		while (n < argc)
			add_back_lst(header, ft_atoi(argv[n++]));
	}
	else
		return (0);
	print_list(*header);

	return (0);
}
