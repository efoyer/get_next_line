/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efoyer <efoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:33:21 by efoyer            #+#    #+#             */
/*   Updated: 2025/10/30 11:05:03 by efoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_files(int fd, char *stash)
{
	char	*buffer;
	int		res_read;
	char	*temp;

	res_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (res_read > 0)
	{
		res_read = read(fd, buffer, BUFFER_SIZE);
		if (res_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[res_read] = '\0';
		temp = free_join(stash, buffer);
		if (!temp)
			return (free(buffer), NULL);
		stash = temp;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*set_stash(char *stash)
{
	char	*new_buff;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == ft_strlen(stash))
		return (free(stash), NULL);
	new_buff = malloc(ft_strlen(stash) - i + 1);
	if (!new_buff)
		return (free(stash), NULL);
	j = 0;
	while (stash[i + j])
	{
		new_buff[j] = stash[i + j];
		j++;
	}
	new_buff[j] = '\0';
	return (free(stash), new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_files(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!buffer[0])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = set_stash(buffer);
	return (line);
}

/*int main(void)
{
	int		fd;
	char	*line;
	int		i;

	// Test 1: Fichier normal
	printf("=== Test 1: Fichier normal ===\n");
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur d'ouverture du fichier\n");
		return (1);
	}
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Ligne %d: %s", i++, line);
		free(line);
	}
	close(fd);

	// Test 2: Fichier vide
	printf("\n=== Test 2: Fichier vide ===\n");
	fd = open("empty.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Résultat: %s\n", line ? line : "NULL");
	free(line);
	close(fd);

	// Test 3: FD invalide
	printf("\n=== Test 3: FD invalide ===\n");
	line = get_next_line(-1);
	printf("Résultat: %s\n", line ? line : "NULL");
	
	line = get_next_line(9999);
	printf("Résultat: %s\n", line ? line : "NULL");

	// Test 4: Fichier avec 1 caractère
	printf("\n=== Test 4: Fichier 1 caractère ===\n");
	fd = open("1char.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Ligne 1: %s\n", line ? line : "NULL");
	free(line);
	line = get_next_line(fd);
	printf("Ligne 2: %s\n", line ? line : "NULL");
	free(line);
	close(fd);

	// Test 5: Appels multiples sur même FD
	printf("\n=== Test 5: Appels multiples ===\n");
	fd = open("test.txt", O_RDONLY);
	for (i = 0; i < 3; i++)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("Ligne %d: %s", i + 1, line);
			free(line);
		}
	}
	close(fd);

	return (0);
}*/
