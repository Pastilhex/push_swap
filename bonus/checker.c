/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:40:10 by pastilhex         #+#    #+#             */
/*   Updated: 2023/05/19 19:11:59 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char	**argv)
{
	int		n;


	n = 1;
	if (argc == 1)
		exit (0);
	else
		while (n < argc)
		{
			if (check_digit(argv[n]) != 1)
				display_error();
			n++;
		}
	n = 0;
	

	
	
	return (0);
}
