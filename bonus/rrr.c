/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:00:54 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 18:23:29 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_sort *sort, t_list **header_a, t_list **header_b)
{
	rra(sort, header_a);
	rrb(sort, header_b);
}
