/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:55:09 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/18 20:59:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_one(t_sort *s)
{
	s->rra = s->ha_size - s->ra;
	s->rr = 0;
	s->ra = 0;
	s->rrb = 0;
	s->rrr = 0;
}

void	count_two(t_sort *s)
{
	if (s->ra > s->rb && s->rb == 0)
	{
		s->rr = 0;
		s->rra = 0;
		s->rrr = 0;
		s->rrb = 0;
	}
	else if (s->ra > s->rb && s->rb <= s->hb_size / 2)
	{
		s->rr = s->rb;
		s->ra = s->ra - s->rb;
		s->rb = s->rb - s->rr;
		s->rra = 0;
		s->rrr = 0;
		s->rrb = 0;
	}
	else if (s->ra > s->rb && s->rb > s->hb_size / 2)
	{
		s->rr = 0;
		s->rb = 0;
		s->rrb = s->hb_size - s->counter;
		s->rra = 0;
		s->rrr = 0;
	}
}

void	count_three(t_sort *s)
{
	s->rra = 0;
	s->rrr = 0;
	s->rrb = 0;
	if (s->ra < s->rb && s->ra == 0)
	{
		s->rr = 0;
		s->rb = s->rb - s->rr;
		s->ra = 0;
	}
	else if (s->ra < s->rb && s->ra > 0)
	{
		s->rr = s->ra;
		s->rb = s->rb - s->rr;
		s->ra = 0;
	}
	else if (s->ra == s->rb)
	{
		s->rr = s->rb;
		s->ra = 0;
		s->rb = 0;
	}
}

void	count_four(t_sort *s)
{
	if (s->ha_size - s->ra > s->hb_size - s->counter)
	{
		s->rrb = 0;
		s->rra = (s->ha_size - s->ra) - (s->hb_size - s->counter);
		s->rrr = (s->hb_size - s->counter);
	}
	else if (s->ha_size - s->ra < s->hb_size - s->counter)
	{
		s->rra = 0;
		s->rrb = (s->hb_size - s->counter) - (s->ha_size - s->ra);
		s->rrr = (s->ha_size - s->ra);
	}
	else if ((s->ha_size - s->ra) == (s->hb_size - s->counter))
	{
		s->rrr = (s->ha_size - s->ra);
		s->rrb = 0;
		s->rra = 0;
	}
	s->ra = 0;
	s->rb = 0;
	s->rr = 0;
}

void	count_five(t_sort *s)
{
	s->rr = 0;
	s->rra = 0;
	s->rrb = 0;
	s->rrr = 0;
	if (s->ra > s->rb && s->rb == 0)
	{
		s->rb = 0;
	}
	else if (s->ra > s->rb && s->rb > 0)
	{
		s->rb = 0;
		s->rrb = s->hb_size - s->counter;
	}
	else if (s->ra < s->rb && s->ra == 0)
	{
		s->rb = 0;
		s->rrb = s->hb_size - s->counter;
	}
	else if (s->ra < s->rb && s->ra > 0)
	{
		s->rb = 0;
		s->rrb = s->hb_size - s->counter;
	}
}
