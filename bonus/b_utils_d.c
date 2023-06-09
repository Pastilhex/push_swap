/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:06 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

int	check_digit(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '-')
		i++;
	else if (input[i] == '\0')
		return (0);
	while (input[i] != '\0')
		if (!ft_isdigit(input[i++]))
			return (0);
	if (ft_atoll(input) < INT_MIN || ft_atoll(input) > INT_MAX)
		return (0);
	return (1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(1, &s[i++], 1);
}

int	ft_strcmp(char *one, char *two)
{
	int	n;

	n = -1;
	if (len(one) == len(two))
	{
		while (++n < len(one))
			if (one[n] != two[n])
				return (0);
		return (1);
	}
	else
		return (0);
}
