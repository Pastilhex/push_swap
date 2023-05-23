/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:43 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/23 14:33:43 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long long int	value;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	t_list	*list;
	int		last_value_a;
	int		last_value_b;
	int		smallest;
	int		biggest;
	t_list	*a;
	t_list	*b;
}	t_sort;

//Base Functions
t_list		*new_list(long long nbr);
t_list		*find_last(t_list *list);
void		add_front_list(t_list **header_a, t_list *list, int nbr);
void		add_back_list(t_list **header_a, int nbr);
void		begin(t_list **header_a, t_list **header_b);
void		else_main(int argc, char **argv, t_list **ha, t_list **hb);
void		more_main(int argc, char**argv, t_list **ha, t_list **hb);
int			check_digit(char *input);
void		display_error(t_list **header_a, t_list **header_b);
int			find_last_value(t_list *list);
void		free_push_swap(t_list **header_a, t_list **header_b);
long long	ft_atoll(const char *str);
int			ft_isdigit(int c);
void		ft_putstr(char *s);
int			ft_strcmp(char *one, char *two);
void		go_to_gnl(t_sort *sort, t_list **header_a, t_list **header_b);
int			size_list(t_list **header);
void		sorted(t_sort *sort, t_list **header_a, t_list **header_b);
int			verify_order(t_list **header);
void		apply_move(t_sort *s, t_list **ha, t_list **hb, char *tmp);
void		error_no_move(t_list **header_a, t_list **header_b, char *tmp);
void		error_not_numeric(t_list **header_a, t_list **header_b);

//Operation Functions
void		sa(t_list **header);
void		sb(t_list **header);
void		ss(t_list **header_a, t_list **header_b);
void		pa(t_list **header_a, t_list **header_b);
void		pb(t_list **header_a, t_list **header_b);
void		ra(t_sort *sort, t_list **header);
void		rb(t_sort *sort, t_list **header);
void		rr(t_sort *sort, t_list **header_a, t_list **header_b);
void		rra(t_sort *sort, t_list **header);
void		rrb(t_sort *sort, t_list **header);
void		rrr(t_sort *sort, t_list **header_a, t_list **header_b);

#endif
