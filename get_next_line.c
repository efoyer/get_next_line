/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efoyer <efoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:06:14 by efoyer            #+#    #+#             */
/*   Updated: 2025/10/28 13:12:18 by efoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"



static char	*read_files(int fd, char *str)
{
	char	*buffer;
	int		nb_read;

	nb_read = -1;
	if (!str)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[nb_read] = 0;
		str = free_join(str, buffer);
		if (ft_strchr(str, '\0'))
			break ;
	}
	free(buffer);
	return (str);
}

static char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\0' || str[i] == '\n')
		line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_files(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);

	return (line);
}
