/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/30 15:21:01 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_images(t_vars *vars)
{
	int				y;
	int				x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->character.pos_y = y;
				vars->character.pos_x = x;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, x * IMG_RES, y * IMG_RES);
			}
			
			/*
			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, x * IMG_RES, y * IMG_RES);
			*/
			x++;			
		}
		y++;
	}
	return (0);
}
