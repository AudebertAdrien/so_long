/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:39:20 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/08 11:06:00 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free_and_join(char *stash, char *buf)
{
	char	*temp;

	temp = ft_strjoin(stash, buf);
	free(stash);
	return (temp);
}

char	*read_file(int fd)
{
	char	buf[BUFFER_SIZE];
	int		bytes_read;
	char	*str;

	bytes_read = 1;
	str = ft_calloc(1, 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		str = ft_free_and_join(str, buf);
		if (!str)
			return (NULL);
	}
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_file(char *map_name)
{
	int		fd;
	char	*str;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		error_message("open file error");
		exit(0);
	}
	str = read_file(fd);
	if (!str)
	{
		error_message("read or empty file");
		exit(0);
	}
	return (str);
}
