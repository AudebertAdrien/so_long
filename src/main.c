/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/30 17:10:43 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map_size(t_vars *vars, int y, int x)
{
	vars->map_y_size = y;
	vars->map_x_size = x;
}

void	initialize_c(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'C')
		vars->count_collectible += 1;
}

void	initialize_e(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'E')
	{
		vars->exit.pos_y = y;
		vars->exit.pos_x = x;
		vars->count_exit += 1;
	}
}

void	initialize_p(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'P')
	{
		vars->character.pos_y = y;
		vars->character.pos_x = x;
		vars->count_character += 1;
	}
}

void	initialize_data(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	vars->count_moves = 0;
	vars->count_collectible = 0;
	vars->count_exit = 0;
	vars->count_character = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			initialize_c(vars, y, x);
			initialize_e(vars, y, x);
			initialize_p(vars, y, x);
			x++;
		}
		y++;
	}
	initialize_map_size(vars, y, x);
}

int	main(int argc, char *argv[])
{	
	t_vars	vars;
	char 	*line;

	if (argc != 2)
		ft_is_error("Must be only one argument");	
	if (check_file_name(argv[1]))	
		ft_is_error("The name of the card must end with .ber");
	line = get_file(argv[1]);
	printf("\n%s\n", line);
	vars.map = ft_split(line, '\n');
	free(line);

	initialize_data(&vars);
	check_map(&vars);
	open_window(&vars);
	setup_images(&vars);
	initialize_images(&vars);

	mlx_hook(vars.win, 17, 1L << 0, ft_exit, &vars);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop_hook(vars.mlx, initialize_images, &vars);
	printf("\nEND\n");
	mlx_loop(vars.mlx);
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
