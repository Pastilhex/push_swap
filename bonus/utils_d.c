/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/19 19:11:32 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// int	len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

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

void	display_error(void)
{
	ft_putstr("Error\n");
	exit(0);
}
