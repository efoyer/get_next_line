/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efoyer <efoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:06:17 by efoyer            #+#    #+#             */
/*   Updated: 2025/10/28 13:16:05 by efoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

static int	ft_lenmax(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	return (i + j);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_final;
	int		i;
	int		j;

	str_final = malloc(sizeof(char) * ft_lenmax(s1, s2) + 1);
	if (!str_final)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_final[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str_final[i + j] = s2[j];
		j++;
	}
	str_final[i + j] = '\0';
	return (str_final);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	cr;

	i = 0;
	cr = (char)c;
	while (s[i])
	{
		if (s[i] == cr)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cr)
		return ((char *)&s[i]);
	return (NULL);
}

char	*free_join(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free (s1);
	return (tmp);
}
