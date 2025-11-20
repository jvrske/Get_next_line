/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:26:37 by csilva            #+#    #+#             */
/*   Updated: 2025/11/20 09:27:09 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] && c[i] != '\n')
		i++;
	if (c[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*new_s;

	i = 0;
	j = 0;
	total_len = (ft_strlen(s1) + ft_strlen(s2));
	new_s = malloc((total_len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (i + j < total_len)
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	free(s1);
	return (new_s);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return (1);
		if (s[i] == '\0')
		break ;
		i++;
	}
	return (0);
}

void	updt_buffer(char *buf)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = ft_strlen(buf);
	while (i + start < BUFFER_SIZE)
	{
		buf[i] = buf[start + i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}
