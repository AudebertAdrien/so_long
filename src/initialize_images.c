/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:52:33 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/04 13:47:13 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_images(t_vars *vars)
{
	int				y;
	int				x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{

			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == 'P')
			{
				vars->character.pos_y = y;
				vars->character.pos_x = x;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, vars->character.pos_x * IMG_RES, vars->character.pos_y * IMG_RES);
				vars->map[y][x] = '0';
			}
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == 'X')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, x * IMG_RES, y * IMG_RES);
			
			x++;			
		}
		y++;
	}
}
