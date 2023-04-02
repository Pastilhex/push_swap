/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:30 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/02 19:24:13 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*aux;

	if (!lst || !del)
		return ;
	tmp = *lst;
	aux = *lst;
	while (tmp)
	{
		aux = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = aux;
	}
	*lst = NULL;
}
