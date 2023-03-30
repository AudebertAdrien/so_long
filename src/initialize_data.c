/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:20:30 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/30 17:50:47 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map_size(t_vars *vars, int y, int x)
{
	vars->map_y_size = y;
	vars->map_x_size = x;
}

/*
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
*/

void	initialize_el(t_image_data *img, int *count, char el, int y, int x)
{
	if (el != 'C')
	{
		img->pos_y = y;
		img->pos_x = x;
	}
	if (count)
		(*count)++;
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
			initialize_el(&vars->collectible, &vars->count_collectible, 'C', y, x);
			initialize_el(&vars->exit, &vars->count_exit, 'E', y, x);
			initialize_el(&vars->character, &vars->count_character, 'P', y, x);
			x++;
		}
		y++;
	}
	initialize_map_size(vars, y, x);
}
