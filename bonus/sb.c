/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:12:05 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 18:23:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_list **header)
{
	int		tmp;
	t_list	*list;

	if (size_list(header) >= 2)
	{
		list = *header;
		tmp = list->value;
		list->value = list->next->value;
		list->next->value = tmp;
	}
}
