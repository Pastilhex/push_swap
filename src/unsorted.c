/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:58:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 14:09:13 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	unsorted(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;
	t_list	*b;

	a = *ha;
	b = *hb;
	find_smallest(s, *ha);
	find_biggest(s, *ha);
	if (!verify_order(ha))
		ha_not_in_order(s, ha, hb);
	else if (verify_in_order(s, ha) && size_list(hb) == 0)
		ra(s, ha, 0);
	else if (verify_in_order(s, ha) && verify_rev_order(hb)
		&& b->value < a->value && b->value < s->last_value_b
		&& a->value == s->smallest && s->last_value_b == s->biggest)
		pa(ha, hb);
	else if ((a->value > b->value && b->value < s->last_value_b
			&& a->value == s->smallest && s->last_value_b == s->biggest)
		|| (a->value > b->value && b->value < s->last_value_b
			&& a->value < s->last_value_b && verify_rev_in_order(s, hb)))
		pb(ha, hb);
	else
		unsorted_continue(s, ha, hb);
}

void	unsorted_continue(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;
	t_list	*b;

	a = *ha;
	b = *hb;
	if ((a->value > b->value && b->value < s->last_value_b
			&& a->value == s->smallest && s->last_value_b == s->biggest)
		|| (a->value > b->value && b->value < s->last_value_b
			&& a->value > s->last_value_b && verify_rev_in_order(s, hb)))
		rra(s, hb, 0);
	else if ((verify_order(ha) || verify_in_order(s, ha))
		&& verify_rev_in_order(s, hb))
		if ((verify_in_order(s, ha) && verify_rev_in_order(s, hb))
			|| (size_list(hb) == 1 && b->value < a->value))
			pa(ha, hb);
}

void	ha_not_in_order(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;

	a = *ha;
	if (*ha)
		s->last_value_a = find_last_value(*ha);
	if (*hb)
		s->last_value_b = find_last_value(*hb);
	if (size_list(ha) == 2 && a->value > a->next->value)
		sa(ha, 0);
	else if (a->value > a->next->value && a->value > s->last_value_a
		&& a->next->value > s->last_value_a)
		sa(ha, 0);
	else if (a->value > a->next->value && a->value > s->last_value_a
		&& a->next->value < s->last_value_a)
		ra(s, ha, 0);
	else if (a->value > a->next->value && a->value < s->last_value_a
		&& a->next->value < s->last_value_a)
		sa(ha, 0);
	else
		ha_not_in_order_continue(s, ha, hb);
}

void	ha_not_in_order_continue(t_sort *s, t_list **ha, t_list **hb)
{
	t_list	*a;

	a = *ha;
	if (a->value < a->next->value && a->value < s->last_value_a
		&& a->next->value > s->last_value_a)
		sa(ha, 0);
	else if (a->value < a->next->value && a->value > s->last_value_a
		&& a->next->value > s->last_value_a)
		rra(s, ha, 0);
	else if (size_list(hb) < 2 && a->value < a->next->value
		&& a->value < s->last_value_a && a->next->value < s->last_value_a)
		pb(ha, hb);
	else if (size_list(hb) > 1 && a->value < a->next->value
		&& a->value < s->last_value_a && a->next->value < s->last_value_a)
		sort_list_a(s, ha, hb);
}

long long	ft_atoll(const char *str)
{
	int			i;
	long long	s;
	long long	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (s * res);
}
