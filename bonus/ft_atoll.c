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
