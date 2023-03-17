/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:39:20 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/17 17:47:30 by aaudeber         ###   ########.fr       */
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
	char *str;

	char *test;
	bytes_read = 1;
	str = ft_calloc(1, 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			printf("An error occured while trying to read file.\n");
			return (NULL);
		}
		buf[bytes_read] = '\0';
		str = ft_free_and_join(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_file()
{
	int	fd;

	fd = open("map/map_1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("An error occured while trying to open file.\n");
		return (0);
	}
	return (read_file(fd));
}


