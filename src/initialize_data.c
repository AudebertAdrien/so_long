/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:20:30 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/05 16:42:47 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map_size(t_vars *vars, int y, int x)
{
	vars->map_y_size = y;
	vars->map_x_size = x;
}

void	define_elements(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'C')
	{
		vars->collectible.pos_y = y;
		vars->collectible.pos_x = x;
		vars->count_collectible++;
	}
	if (vars->map[y][x] == 'E')
	{
		vars->exit.pos_y = y;
		vars->exit.pos_x = x;
		vars->count_exit++;
	}
	if (vars->map[y][x] == 'P')
	{
		vars->character.pos_y = y;
		vars->character.pos_x = x;
		vars->count_character++;
	}
}

void	setup_struct_variable(t_vars *vars)
{
	vars->count_moves = 0;
	vars->count_collectible = 0;
	vars->count_exit = 0;
	vars->count_character = 0;
	vars->exit_parsed = 0;
	vars->collectible_parsed = 0;
}

void	initialize_data(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	setup_struct_variable(vars);
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			define_elements(vars, y, x);
			x++;
		}
		y++;
	}
	initialize_map_size(vars, y, x);
}
