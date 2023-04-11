/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:45:01 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/11 16:32:08 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **header_a, t_list **header_b, int flag)
{
	printf("rr\n");
	flag = 1;
	ra(header_a, flag);
	rb(header_b, flag);
}
