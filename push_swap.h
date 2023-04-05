/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:43 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/05 12:04:48 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int	value;
	struct s_list *next;
}	t_list;

t_list	*newlst(int nbr);
void	add_front_lst(t_list **header, t_list *list, int nbr);
void	add_back_lst(t_list **header, int nbr);
t_list	*find_last(t_list *list);
void	print_list(t_list *list);

#endif
