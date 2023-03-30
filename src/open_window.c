/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:00:02 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/30 12:10:11 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_is_error("mlx init()");
	vars->win = mlx_new_window(vars->mlx, IMG_RES * vars->map_x_size, IMG_RES * vars->map_y_size, "Hello world!");
	if (vars->win == NULL)
	{
		free(vars->win);
		ft_is_error("mlx new window()");
	}
	return (0);
}
