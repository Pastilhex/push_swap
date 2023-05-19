/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:11:38 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 18:23:31 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **header)
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
