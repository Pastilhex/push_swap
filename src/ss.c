/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:24:34 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/18 12:52:37 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **header_a, t_list **header_b, int flag)
{
	ft_putstr("ss\n");
	flag = 1;
	sa(header_a, flag);
	sb(header_b, flag);
}
