/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:43 by pastilhex         #+#    #+#             */
/*   Updated: 2023/04/25 19:16:32 by ialves-m         ###   ########.fr       */
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
	int		print;
	int		first_run;
	int		last_value_a;
	int		last_value_b;
	int		smallest;
	int		biggest;
	int		full_size;
	int		total_sum;
	int		big_flag;
	int		start_point;
	int		count;
	int		x;
	t_list	*a;
	t_list	*b;
}	t_sort;

//Base Functions
t_list	*new_list(long long nbr);
t_list	*find_last(t_list *list);
void	add_front_list(t_list **header_a, t_list *list, int nbr);
void	add_back_list(t_list **header_a, int nbr);
void	print_list(t_list *list);
int		size_list(t_list **header);
long long	ft_atoll(const char *str);
int		ft_isdigit(int c);
int		check_digit(char *input);
void	ft_putstr(char *s);
void	display_error(void);
void	begin(t_list **header_a, t_list **header_b);
void	find_smallest(t_sort *sort, t_list *list);
void	find_biggest(t_sort *sort, t_list *list);
int		find_last_value(t_list *list);
void	pp(t_list **header_a, t_list **header_b);
int		verify_order(t_list **header);
int		verify_in_order(t_sort	*sort, t_list **header);
int		verify_rev_order(t_list **header);
int		steps_to_big(t_sort *sort, t_list *list);
int		steps_to_value(t_sort *sort, t_list *list, int value);
int		half_list(t_list **header);
int		sum_list(t_list **header);
int		verify_rev_in_order(t_sort	*sort, t_list **header);
int		steps_to(t_sort *sort, t_list *list, int value);
void	choose_side(t_sort *s, t_list **ha, t_list **hb);
void	restart_sort(t_sort *s, t_list **ha, t_list **hb);

//Operation Functions
void	sa(t_list **header, int flag);
void	sb(t_list **header, int flag);
void    ss(t_list **header_a, t_list **header_b, int flag);
void	pa(t_list **header_a, t_list **header_b);
void	pb(t_list **header_a, t_list **header_b);
void	ra(t_sort *sort, t_list **header, int flag);
void	rb(t_sort *sort, t_list **header, int flag);
void	rr(t_sort *sort, t_list **header_a, t_list **header_b, int flag);
void	rra(t_sort *sort, t_list **header, int flag);
void	rrb(t_sort *sort, t_list **header, int flag);
void	rrr(t_sort *sort, t_list **header_a, t_list **header_b, int flag);
void	unsorted(t_sort *sort, t_list **header_a, t_list **header_b);
void	sorted(t_sort *sort, t_list **header_a, t_list **header_b);
void	sort_list_a(t_sort *s, t_list **ha, t_list **hb);
void	big_list(t_sort *s, t_list **header_a, t_list **header_b);
void	big_unsorted(t_sort *s, t_list **header_a, t_list **header_b);

#endif
