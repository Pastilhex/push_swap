/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:52:27 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/09 11:34:40 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	find_last_value(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list->value);
}

void	find_smallest(t_sort *sort, t_list *list)
{
	if (list != NULL)
		sort->smallest = INT_MAX;
	else
		sort->smallest = list->value;
	while (list != NULL)
		if (list->value > sort->smallest)
			list = list->next;
		else if (list->value < sort->smallest)
		{
			sort->smallest = list->value;
			list = list->next;
		}
}

void	find_biggest(t_sort *sort, t_list *list)
{
	if (list != NULL)
		sort->biggest = INT_MIN;
	else
		sort->biggest = list->value;
	while (list != NULL)
		if (list->value < sort->biggest)
			list = list->next;
		else if (list->value > sort->biggest)
		{
			sort->biggest = list->value;
			list = list->next;
		}
}

int	steps_to_big(t_sort *sort, t_list *list)
{
	int	i;

	i = 0;
	sort->biggest = INT_MIN;
	while (list->next != NULL)
		if (list->value < sort->biggest)
			list = list->next;
		else if (list->value > sort->biggest)
		{
			i++;
			list = list->next;
		}
	return (i);
}

int	steps_to_value(t_sort *sort, t_list *list, int value)
{
	int	i;

	i = 0;
	(void) sort;
	while (list->next != NULL)
	{
		i++;
		if ((value > list->value && value < list->next->value)
			|| (list->value == sort->smallest && list->next->value == sort->biggest)
			|| (sort->last_value_b == sort->smallest && list->value == sort->biggest))
			return (i);
		else
			list = list->next;
	}
	return (i);
}

int	steps_to(t_sort *sort, t_list *list, int value)
{
	int	i;

	i = 0;
	(void) sort;
	while (list->next != NULL)
	{
		i++;
		if ((value > list->value && value < list->next->value)
			|| (list->value == sort->smallest && list->next->value == sort->biggest)
			|| (sort->last_value_b == sort->smallest && list->value == sort->biggest)
			|| (value < list->value && value > list->next->value))
			return (i);
		else
			list = list->next;
	}
	return (i);
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
		printf("%lld ", list->value);
		list = list->next;
	}
	printf("\n");
	if (list != NULL)
		printf("\n");
}

void	pp(t_list **header_a, t_list **header_b)
{
	(void) header_a;
	(void) header_b;

 	printf("\n");
 	//printf("list a: ");
 	print_list(*header_a);
 	//printf("list b: ");
 	print_list(*header_b);
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

int	verify_order(t_list **header)
{
	t_list	*list;

	list = *header;
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	verify_order_x(t_list **header, int x)
{
	t_list	*list;
	int		xtimes;

	xtimes = 0;
	list = *header;
	while (list->next != NULL && xtimes < x)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
		xtimes++;
	}
	return (1);
}

int	verify_in_order(t_sort	*sort, t_list **header)
{
	t_list	*list;

	list = *header;
	find_smallest(sort, *header);
	find_biggest(sort, *header);
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
		{
			if (list->value == sort->biggest && list->next->value == sort->smallest)
				list = list->next;
			else
				return (0);
		}
		if (list->next != NULL)
			list = list->next;
	}
	//printf("verify in order\n");
	return (1);
}

int	verify_rev_order(t_list **header)
{
	t_list	*list;

	list = *header;
	while (list->next != NULL)
	{
		if (list->value < list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	verify_rev_in_order(t_sort	*sort, t_list **header)
{
	t_list	*list;

	list = *header;
	find_smallest(sort, *header);
	find_biggest(sort, *header);
	while (list->next != NULL)
	{
		if (list->value < list->next->value)
		{
			if (list->value == sort->smallest && list->next->value == sort->biggest)
				list = list->next;
			else
				return (0);
		}
		if (list->next != NULL)
			list = list->next;
	}
	//printf("verify in order\n");
	return (1);
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