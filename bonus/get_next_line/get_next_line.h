/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:02:06 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/24 17:46:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include   "../checker.h"
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<wchar.h>

int		len(char *word);
char	*join(char *s1, char *s2);
int		find(char *str, char c);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_move(char *tmp);

#endif
