/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:58:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 18:23:02 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	free_a(t_list *list_a, t_list *begin_a)
{
	while (list_a != NULL)
	{
		begin_a = list_a->next;
		free (list_a);
		list_a = begin_a;
	}
	if (begin_a)
		free(begin_a);
}

void	free_b(t_list *list_b, t_list *begin_b)
{
	while (list_b != NULL)
	{
		begin_b = list_b->next;
		free (list_b);
		list_b = begin_b;
	}
	if (begin_b)
		free(begin_b);
}
