/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/20 15:28:53 by aaudeber         ###   ########.fr       */
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
	char	**map;
	char	**tab;

	line = get_file();
	printf("\n%s\n", line);

	map = ft_split(line, '\n');

	open_window(&vars);
	tab = setup_image();
	//display_image(&vars, map);
	printf("END\n");

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

	mlx_key_hook(vars.win, key_press, &vars);
	//mlx_loop_hook(vars.mlx, ft_test, &vars);
	mlx_loop(vars.mlx);

	free(line);
	free(map);
	return (0);
}
