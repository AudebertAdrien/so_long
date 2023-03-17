/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/17 11:53:29 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{	
	int		fd;
	int		bytes_read;
	char	buf[100];
	t_vars	vars;
	char	**tab;

	printf("\nHELLO WORLD\n");
	fd = open("map/map_1.txt", O_RDONLY);
	printf("%d\n", fd);
	if (fd == -1)
	{
		printf("An error occured while trying to open file.\n");
		return (0);
	}
	bytes_read = read(fd, buf, 100);	
	if (bytes_read == -1)
	{
		printf("An error occured while trying to read file.\n");
		return (0);
	}
	printf("END\n");

	tab = ft_split(buf, '\n');	
	open_window(&vars);
	display_image(&vars);
	
	//mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);
	free(tab);
	return (0);
}
