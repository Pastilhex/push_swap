/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:00:54 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/11 16:27:16 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **header_a, t_list **header_b, int flag)
{
	printf("rrr\n");
	flag = 1;
	rra(header_a, flag);
	rrb(header_b, flag);
}
