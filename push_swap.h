/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:43 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/10 21:02:26 by pastilhex        ###   ########.fr       */
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
t_list	*new_list(int nbr);
t_list	*find_last(t_list *list);
void	add_front_list(t_list **header_a, t_list *list, int nbr);
void	add_back_list(t_list **header_a, int nbr);
void	print_list(t_list *list);
int		size_list(t_list **header);
int		ft_atoi(const char *str);

//Operation Functions
void	sa(t_list **header);
void	sb(t_list **header);
void    ss(t_list **header_a, t_list **header_b);
void	pa(t_list **header_a, t_list **header_b);
void	pb(t_list **header_a, t_list **header_b);
void	ra(t_list **header);
void	rb(t_list **header);
void	rr(t_list **header_a, t_list **header_b);
void	rra(t_list **header);
void	rrb(t_list **header);
void	rrr(t_list **header_a, t_list **header_b);

#endif
