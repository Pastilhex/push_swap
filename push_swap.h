/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:43 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/06 22:09:44 by pastilhex        ###   ########.fr       */
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


//Base Functions
t_list	*newlst(int nbr);
void	add_front_lst(t_list **header_a, t_list *list, int nbr);
void	add_back_lst(t_list **header_a, int nbr);
t_list	*find_last(t_list *list);
void	print_list(t_list *list);
int		ft_atoi(const char *str);

//Operation Functions
void	sa(t_list *list);
void	sb(t_list *list);
void	ss(t_list *list_a, t_list *list_b);
void	pa(t_list **header_a, t_list **header_b);

#endif
