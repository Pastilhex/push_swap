/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:43 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/24 17:37:42 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
}	t_sort;

//Base Functions
t_list		*new_list(long long nbr);
t_list		*find_last(t_list *list);
void		add_front_list(t_list **header_a, t_list *list, int nbr);
void		add_back_list(t_list **header_a, int nbr);
void		begin(t_list **header_a, t_list **header_b);
void		big_list(t_sort *s, t_list **header_a, t_list **header_b);
void		big_unsorted(t_sort *s, t_list **header_a, t_list **header_b);
int			check_digit(char *input);
void		count_steps(t_sort *sort, t_list *ha, t_list *hb);
void		count_one(t_sort *s);
void		count_two(t_sort *s);
void		count_three(t_sort *s);
void		count_four(t_sort *s);
void		count_five(t_sort *s);
void		count_final_steps(t_sort *s);
void		display_error(void);
void		display_free_error(t_list **header_a, t_list **header_b);
void		else_main(int argc, char **argv, t_list **ha, t_list **hb);
void		final_sort(t_sort *s, t_list **ha, t_list **hb);
void		find_smallest(t_sort *sort, t_list *list);
void		find_biggest(t_sort *sort, t_list *list);
int			find_last_value(t_list *list);
void		free_push_swap(t_list **header_a, t_list **header_b);
long long	ft_atoll(const char *str);
int			ft_isdigit(int c);
void		ft_putstr(char *s);
void		ha_not_in_order(t_sort *s, t_list **ha, t_list **hb);
void		ha_not_in_order_continue(t_sort *s, t_list **ha, t_list **hb);
void		more_main(int argc, char**argv, t_list **ha, t_list **hb);
int			size_list(t_list **header);
int			steps_to_smallest(t_sort *sort, t_list *list, int value);
int			steps_to_value(t_sort *sort, t_list *list, int value);
int			steps_to(t_sort *sort, t_list *list, int value);
void		sorted(t_sort *sort, t_list **header_a, t_list **header_b);
void		sort_list_a(t_sort *s, t_list **ha, t_list **hb);
int			verify_order(t_list **header);
int			verify_in_order(t_sort	*sort, t_list **header);
int			verify_rev_order(t_list **header);
int			verify_rev_in_order(t_sort	*sort, t_list **header);
void		sort_ha(t_sort *s, t_list **ha, t_list **hb);
void		sort_ha_continue(t_sort *s, t_list **ha, t_list **hb);
void		sort_list_aa(t_sort *s, t_list **ha, t_list **hb);
void		sort_list_aaa(t_sort *s, t_list **ha, t_list **hb);
void		unsorted_continue(t_sort *s, t_list **ha, t_list **hb);
void		unsorted(t_sort *sort, t_list **header_a, t_list **header_b);
void		free_a(t_list *list_a, t_list *begin_a);
void		free_b(t_list *list_b, t_list *begin_b);

//Operation Functions
void		sa(t_list **header, int flag);
void		sb(t_list **header, int flag);
void		ss(t_list **header_a, t_list **header_b, int flag);
void		pa(t_list **header_a, t_list **header_b);
void		pb(t_list **header_a, t_list **header_b);
void		ra(t_sort *sort, t_list **header, int flag);
void		rb(t_sort *sort, t_list **header, int flag);
void		rr(t_sort *sort, t_list **header_a, t_list **header_b, int flag);
void		rra(t_sort *sort, t_list **header, int flag);
void		rrb(t_sort *sort, t_list **header, int flag);
void		rrr(t_sort *sort, t_list **header_a, t_list **header_b, int flag);

#endif
