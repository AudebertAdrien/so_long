/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:24:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/08 19:34:19 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_square(t_vars *vars, int tmp, int x, int y)
{
	if (tmp != x && y != 0)
		is_map_error(vars, "Map is not square!");
}

void	is_surrounded_by_wall(t_vars *vars, int max_y, int max_x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < max_y)
	{
		j = 0;
		while (j < max_x)
		{
			if (i == 0 && vars->map_cpy[i][j] != '1')
				is_map_error(vars, "Map is not surrounded by walls");
			if (vars->map_cpy[i][0] != '1' ||
					vars->map_cpy[i][max_x - 1] != '1')
				is_map_error(vars, "Map is not surrounded by walls");
			if (i == max_y - 1 && vars->map_cpy[i][j] != '1')
				is_map_error(vars, "Map is not surrounded by walls");
			j++;
		}
		i++;
	}
}

void	check_elements(t_vars *vars, int y, int x)
{
	if (!ft_strchr("01CEP", vars->map_cpy[y][x]))
		is_map_error(vars, "map contains invalid elements");
	if (vars->count_exit != 1)
		is_map_error(vars, "map contains invalid number of exits");
	if (vars->count_character != 1)
		is_map_error(vars, "map contains invalid number of characters");
	if (vars->count_collectible == 0)
		is_map_error(vars, "map contains invalid number of collectible");
}	

void	check_map(t_vars *vars)
{
	int	y;
	int	x;
	int	tmp;

	y = 0;
	x = 0;
	tmp = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			check_elements(vars, y, x);
			x++;
		}
		is_square(vars, tmp, x, y);
		tmp = x;
		y++;
	}
	is_surrounded_by_wall(vars, y, x);
}
