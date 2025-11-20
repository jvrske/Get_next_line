/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:26:22 by csilva            #+#    #+#             */
/*   Updated: 2025/11/20 13:31:56 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[__FD_SETSIZE][BUFFER_SIZE + 1];
	char		*line;
	__ssize_t	byte_r;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > __FD_SETSIZE)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[fd][0] == 0)
		{
			byte_r = read(fd, buffer[fd], BUFFER_SIZE);
			if (byte_r == -1)
				return (NULL);
			if (byte_r == 0)
				return (line);
		}
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (NULL);
		updt_buffer(buffer[fd]);
		if (ft_strchr(line, '\n'))
			return (line);
	}
}

int	main(void)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	i = open("test1.txt", O_RDONLY);
	res = get_next_line(i);
	printf("%s\n", res);
	free(res);

	j = open("test2.txt", O_RDONLY);
	res = get_next_line(j);
	printf("%s\n", res);
	free(res);

	k = open("test3.txt", O_RDONLY);
	res = get_next_line(k);
	printf("%s\n", res);
	free(res);

	close(i);

}
