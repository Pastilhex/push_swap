/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:00:54 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/18 12:54:08 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_sort *sort, t_list **header_a, t_list **header_b, int flag)
{
	ft_putstr("rrr\n");
	flag = 1;
	rra(sort, header_a, flag);
	rrb(sort, header_b, flag);
}
