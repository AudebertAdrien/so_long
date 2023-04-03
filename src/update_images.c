/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/03 11:55:55 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_images(t_vars *vars)
{
	int				y;
	int				x;
	char 			*counted_moves; 

	counted_moves = ft_itoa(vars->count_moves);
	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, x * IMG_RES, y * IMG_RES);
			if (vars->map[y][x] == 'P')
			{
				vars->character.pos_y = y;
				vars->character.pos_x = x;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, x * IMG_RES, y * IMG_RES);
			}
			if (vars->map[y][x] == 'X')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, x * IMG_RES, y * IMG_RES);
			
			x++;			
		}
		y++;
	}
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0x000000 , counted_moves);
	free(counted_moves);
	return (0);
}
