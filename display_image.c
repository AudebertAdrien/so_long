/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/23 16:10:27 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
/*
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
*/
int	display_image(t_vars *vars)
{
	int				y;
	int				x;
	
	//int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			mlx_string_put(vars->mlx, vars->win, 10, 10, create_trgb(0,0,0,255), "TEST");

			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, x * 32, y * 32);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x * 32, y * 32);
			if (vars->map[y][x] == 'c')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, x * 32, y * 32);
			if (vars->map[y][x] == 'p')
			{
				vars->character.pos_y = y;
				vars->character.pos_x = x;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, x * 32, y * 32);
			}
			if (vars->map[y][x] == 'e')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, x * 32, y * 32);
			x++;			
		}
		y++;
	}
	return (0);
}
