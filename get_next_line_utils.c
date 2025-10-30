/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efoyer <efoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:33:18 by efoyer            #+#    #+#             */
/*   Updated: 2025/10/30 10:46:56 by efoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*free_join(char *s1, char *s2)
{
	char	*t;

	t = ft_strjoin(s1, s2);
	if (!t)
		return (free(s1), NULL);
	free(s1);
	return (t);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_final;
	int		i;
	int		j;

	str_final = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_final)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			str_final[i] = s1[i];
			i++;
		}
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

	if (!s)
		return (NULL);
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
