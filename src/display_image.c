/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/27 16:27:55 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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
			//mlx_string_put(vars->mlx, vars->win, 10, 10, create_trgb(0,0,0,0), ft_itoa(vars->count_moves));

			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, x * 32, y * 32);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x * 32, y * 32);
			if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, x * 32, y * 32);
			if (vars->map[y][x] == 'P')
			{
				vars->character.pos_y = y;
				vars->character.pos_x = x;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, x * 32, y * 32);
			}
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, x * 32, y * 32);
			x++;			
		}
		y++;
	}
	return (0);
}
