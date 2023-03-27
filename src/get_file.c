/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:39:20 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/27 17:56:39 by aaudeber         ###   ########.fr       */
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
			ft_is_error(strerror(errno));
			return (NULL);
		}
		buf[bytes_read] = '\0';
		str = ft_free_and_join(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_file(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_is_error(strerror(errno));
		return (NULL);
	}
	return (read_file(fd));
}

