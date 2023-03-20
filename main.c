/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/20 18:01:23 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(void)
{	
	t_vars	vars;
	char 	*line;

	line = get_file();
	printf("\n%s\n", line);
	vars.map = ft_split(line, '\n');

	open_window(&vars);
	setup_image(&vars);
	display_image(&vars);

	printf("END\n");
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop_hook(vars.mlx, display_image, &vars);
	mlx_loop(vars.mlx);

	free(line);
	return (0);
}
	/*
	void *f;
	void *args;

	f = ft_test;
	args = &vars;

	while (1)
	{
		f(args);
	}
	*/
