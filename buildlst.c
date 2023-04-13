/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/13 11:56:48 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	find_smallest(t_sort *sort, t_list *list)
{
	sort->smallest = list->value;
	while (list->next != NULL)
		if (list->value < list->next->value)
			list = list->next;
		else if (list->value > list->next->value)
		{
			sort->smallest = list->next->value;
			list->value = list->next;
		}
}

t_list	*new_list(long long nbr)
{
	t_list	*var;

	var = (t_list *)malloc(sizeof(t_list));
	if (var)
	{
		var->value = nbr;
		var->next = NULL;
		return (var);
	}
	free (var);
	return (NULL);
}

void	add_front_list(t_list **header, t_list *list, int nbr)
{
	t_list	*new;

	new = new_list(nbr);
	new->next = list;
	*header = new;
}

void	add_back_list(t_list **header, int nbr)
{
	t_list	*new;
	t_list	*last;

	new = new_list(nbr);
	last = find_last(*header);
	last->next = new;
}

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%lld\n", list->value);
		list = list->next;
	}
	if (list != NULL)
		printf("\n");
}

int	size_list(t_list **header)
{
	int		i;
	t_list	*list;

	i = 0;
	list = *header;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	half_list(t_list **header)
{
	int		i;
	int		half;
	int		sum;
	t_list	*list;

	i = 0;
	sum = 0;
	half = size_list(header) / 2;
	list = *header;
	while (list != NULL && i <= half)
	{
		i++;
		sum += list->value;
		list = list->next;
	}
	return (sum);
}

int	sum_list(t_list **header)
{
	int		i;
	int		sum;
	t_list	*list;

	i = 0;
	sum = 0;
	list = *header;
	while (list != NULL)
	{
		i++;
		sum += list->value;
		list = list->next;
	}
	return (sum);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_isdigit(int c)
{
	if(c >= 48 && c <= 57)
		return c;
	return 0;
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
	exit (0);	
}