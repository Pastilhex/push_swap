/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:43 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 19:10:04 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_gnl
{
	char	*move;
}	t_gnl;

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
	int		counter;
	int		ha_size;
	int		hb_size;
	int		total_nbr_of_steps;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		first_step;
	int		second_step;
	int		final_step;
	int		go_rr;
	int		go_ra;
	int		go_rb;
	int		go_rrr;
	int		go_rra;
	int		go_rrb;
	t_list	*a;
	t_list	*b;
	t_gnl	*g;
}	t_sort;

//Base Functions
t_list		*new_list(long long nbr);
t_list		*find_last(t_list *list);
long long	ft_atoll(const char *str);
void		add_front_list(t_list **header_a, t_list *list, int nbr);
void		add_back_list(t_list **header_a, int nbr);
int			size_list(t_list **header);
int			ft_isdigit(int c);
int			check_digit(char *input);
void		ft_putstr(char *s);
void		display_error(void);
void		begin(t_list **header_a, t_list **header_b);
void		find_smallest(t_sort *sort, t_list *list);
void		find_biggest(t_sort *sort, t_list *list);
int			find_last_value(t_list *list);
int			verify_order(t_list **header);
int			verify_in_order(t_sort	*sort, t_list **header);
int			verify_rev_order(t_list **header);
int			steps_to_smallest(t_sort *sort, t_list *list, int value);
int			steps_to_value(t_sort *sort, t_list *list, int value);
int			verify_rev_in_order(t_sort	*sort, t_list **header);
int			steps_to(t_sort *sort, t_list *list, int value);
void		count_steps(t_sort *sort, t_list *ha, t_list *hb);
void		final_sort(t_sort *s, t_list **ha, t_list **hb);
void		ha_not_in_order(t_sort *s, t_list **ha, t_list **hb);
void		ha_not_in_order_continue(t_sort *s, t_list **ha, t_list **hb);
void		sort_ha(t_sort *s, t_list **ha, t_list **hb);
void		sort_ha_continue(t_sort *s, t_list **ha, t_list **hb);
void		sort_list_aa(t_sort *s, t_list **ha, t_list **hb);
void		sort_list_aaa(t_sort *s, t_list **ha, t_list **hb);
void		count_one(t_sort *s);
void		count_two(t_sort *s);
void		count_three(t_sort *s);
void		count_four(t_sort *s);
void		count_five(t_sort *s);
void		count_final_steps(t_sort *s);
void		unsorted_continue(t_sort *s, t_list **ha, t_list **hb);
void		free_push_swap(t_list **header_a, t_list **header_b);
void		unsorted(t_sort *sort, t_list **header_a, t_list **header_b);
void		sorted(t_sort *sort, t_list **header_a, t_list **header_b);
void		sort_list_a(t_sort *s, t_list **ha, t_list **hb);
void		big_list(t_sort *s, t_list **header_a, t_list **header_b);
void		big_unsorted(t_sort *s, t_list **header_a, t_list **header_b);
void		else_main(int argc, char **argv, t_list **header_a, t_list **header_b);
void		more_main(int argc, char**argv, t_list **header_a, t_list **header_b);

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
