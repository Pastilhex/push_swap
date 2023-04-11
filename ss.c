/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:24:34 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/11 16:33:22 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_list **header_a, t_list **header_b, int flag)
{
	printf("ss\n");
	flag = 1;
	sa(header_a, flag);
	sb(header_b, flag);
}
