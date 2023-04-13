/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:00:54 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/13 15:02:15 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_sort *sort, t_list **header_a, t_list **header_b, int flag)
{
	printf("rrr\n");
	flag = 1;
	rra(sort, header_a, flag);
	rrb(sort, header_b, flag);
}
