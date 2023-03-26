/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:24:19 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/26 15:31:05 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_square(int tmp, int x, int y)
{
	if (tmp != x && y != 0)
		ft_is_error("Map is not square!");
}

void	handle_map(t_vars *vars)
{
	int	y;
	int	x;
	int	tmp;

	tmp = 0;
	y = 0;
	x = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
			x++;
		is_square(tmp, x, y);
		tmp = x;
		y++;
	}
	vars->map_y_size = y;
	vars->map_x_size = x;
}

