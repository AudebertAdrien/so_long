/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:00:02 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/05 16:45:35 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_window(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->map_y_size * IMG_RES;
	x = vars->map_x_size * IMG_RES;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_is_error("mlx init()");
	vars->win = mlx_new_window(vars->mlx, x, y, "Hello world!");
	if (vars->win == NULL)
	{
		free(vars->win);
		ft_is_error("mlx new window()");
	}
	return (0);
}
