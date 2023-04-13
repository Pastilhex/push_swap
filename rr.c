/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:45:01 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/13 15:02:06 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_sort *sort, t_list **header_a, t_list **header_b, int flag)
{
	printf("rr\n");
	flag = 1;
	ra(sort, header_a, flag);
	rb(sort, header_b, flag);
}
