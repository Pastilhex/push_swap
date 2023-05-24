/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:01:47 by ialves-m          #+#    #+#             */
/*   Updated: 2023/05/24 15:07:30 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *estatica, int fd)
{
	char	*buffer;
	int		readsize;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readsize = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!find(buffer, '\n') && readsize > 0)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (readsize == -1)
		{
			free (buffer);
			free (estatica);
			estatica = NULL;
			return (NULL);
		}
		buffer[readsize] = '\0';
		estatica = join(estatica, buffer);
	}
	free (buffer);
	return (estatica);
}

char	*buildline(char *estatica)
{
	int		i;
	char	*line;

	i = 0;
	if (!estatica)
		return (NULL);
	if (!*estatica)
		return (NULL);
	while (estatica[i] != '\n' && estatica[i] != '\0')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (estatica[i] != '\n' && estatica[i])
	{	
		line[i] = estatica[i];
		i++;
	}
	line[i] = estatica[i];
	return (line);
}

char	*buildlast(char *lastrest)
{
	char	*last;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!lastrest)
		return (NULL);
	if (!*lastrest)
	{
		free (lastrest);
		return (NULL);
	}
	while ((lastrest[i] != '\r' || lastrest[i] != '\n') && lastrest[i])
		i++;
	last = ft_calloc((len(lastrest) + 1 - i), sizeof(char));
	if (last)
	{
		while (lastrest[i])
			last[j++] = lastrest[++i];
		last[j] = '\0';
		free (lastrest);
		return (last);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*estatica;

	estatica = get_line(estatica, fd);
	line = buildline(estatica);
	estatica = buildlast(estatica);
	if (check_move(line) == 0)
		free (estatica);
	return (line);
}

int	check_move(char *tmp)
{
	if ((ft_strcmp(tmp, "pa\n")) || (ft_strcmp(tmp, "pb\n"))
		|| (ft_strcmp(tmp, "ra\n")) || (ft_strcmp(tmp, "rb\n"))
		|| (ft_strcmp(tmp, "rra\n")) || (ft_strcmp(tmp, "rrb\n"))
		|| (ft_strcmp(tmp, "rr\n")) || (ft_strcmp(tmp, "rrr\n"))
		|| (ft_strcmp(tmp, "sa\n")) || (ft_strcmp(tmp, "sb\n"))
		|| (ft_strcmp(tmp, "ss\n")))
		return (1);
	return (0);
}
