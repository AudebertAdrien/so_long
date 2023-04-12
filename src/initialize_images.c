/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:52:33 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/12 15:28:12 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_up_images(t_vars *vars, int y, int x)
{
	int	*p_y;
	int	*p_x;

	p_y = &vars->character.pos_y;
	p_x = &vars->character.pos_x;
	if (vars->map[y][x] == '0')
		display_images(vars, vars->background.img, x * IMG_RES, y * IMG_RES);
	if (vars->map[y][x] == '1')
		display_images(vars, vars->wall.img, x * IMG_RES, y * IMG_RES);
	if (vars->map[y][x] == 'C')
		display_images(vars, vars->collectible.img, x * IMG_RES, y * IMG_RES);
	if (vars->map[y][x] == 'P')
	{
		*p_y = y;
		*p_x = x;
		display_images(vars, vars->character.img, \
				*p_x * IMG_RES, *p_y * IMG_RES);
		vars->map[y][x] = '0';
	}
	if (vars->map[y][x] == 'E')
		display_images(vars, vars->exit.img, x * IMG_RES, y * IMG_RES);
}

void	initialize_images(t_vars *vars)
{
	int				y;
	int				x;
	char			*counted_moves;

	counted_moves = ft_itoa(vars->count_moves);
	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			set_up_images(vars, y, x);
			x++;
		}
		y++;
	}
	mlx_string_put(vars->mlx, vars->win, 14, 18, 0xFF0000, counted_moves);
	free(counted_moves);
}
