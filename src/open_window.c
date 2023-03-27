/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:00:02 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/27 15:23:08 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (MLX_ERROR);
	vars->win = mlx_new_window(vars->mlx, 32 * vars->map_x_size, 32 * vars->map_y_size, "Hello world!");
	if (vars->win == NULL)
	{
		free(vars->win);
		return (MLX_ERROR);
	}
	vars->count_moves = 0;
	return (0);
}
