/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:45:01 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/18 12:56:06 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_sort *sort, t_list **header_a, t_list **header_b, int flag)
{
	ft_putstr("rr\n");
	flag = 1;
	ra(sort, header_a, flag);
	rb(sort, header_b, flag);
}
