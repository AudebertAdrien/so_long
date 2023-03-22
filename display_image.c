/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/22 15:57:08 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image(t_vars *vars)
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
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, x * 40, y * 40);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x * 40, y * 40);
			if (vars->map[y][x] == 'c')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, x * 40, y * 40);
			if (vars->map[y][x] == 'p')
			{
				vars->character.pos_y = y;
				vars->character.pos_x = x;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, x * 40, y * 40);
			}
			if (vars->map[y][x] == 'e')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, x * 40, y * 40);
			x++;			
		}
		y++;
	}
	return (0);
}
