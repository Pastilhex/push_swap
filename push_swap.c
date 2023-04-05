/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/05 12:04:57 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	(void) argc;
	(void) argv;
	t_list	*node;
	t_list	**header;

	header = (t_list **)malloc(sizeof(t_list*));
	
	node = newlst(5);

	*header = node;

	add_front_lst(header, node, 10);
	add_back_lst(header, 15);
	print_list(*header);

	return (0);
}
