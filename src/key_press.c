/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/11 15:12:35 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	counted_moves(t_vars *vars)
{
	char	*counted_moves;

	counted_moves = ft_itoa(vars->count_moves);
	display_images(vars, vars->wall.img, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 14, 18, 0xFF0000, counted_moves);
	free(counted_moves);
}

int	display_character(t_vars *vars, int new_x, int new_y)
{
	if (vars->character_direction == 'T')
		display_images(vars, vars->character_top.img, new_x * IMG_RES, new_y * IMG_RES);
	if (vars->character_direction == 'R')
		display_images(vars, vars->character_right.img, new_x * IMG_RES, new_y * IMG_RES);
	if (vars->character_direction == 'L')
		display_images(vars, vars->character_left.img, new_x * IMG_RES, new_y * IMG_RES);
	if (vars->character_direction == 'B')
		display_images(vars, vars->character.img, new_x * IMG_RES, new_y * IMG_RES);
	return (0);
}

int	move_character(t_vars *vars, int new_y, int new_x)
{
	int		pos_y;
	int		pos_x;

	pos_y = vars->character.pos_y * IMG_RES;
	pos_x = vars->character.pos_x * IMG_RES;
	if (vars->map[new_y][new_x] == '1')
		return (0);
	if (vars->map[new_y][new_x] == 'C')
	{
		vars->count_collectible -= 1;
		vars->map[new_y][new_x] = '0';
	}
	if (vars->map[new_y][new_x] == 'E' && vars->count_collectible == 0)
		ft_exit(vars);
	if (vars->map[vars->character.pos_y][vars->character.pos_x] == '0')
		display_images(vars, vars->background.img, pos_x, pos_y);
	if (vars->map[vars->character.pos_y][vars->character.pos_x] == 'E')
		display_images(vars, vars->exit.img, pos_x, pos_y);
	vars->character.pos_y = new_y;
	vars->character.pos_x = new_x;
	display_character(vars, new_x, new_y); 
	vars->count_moves += 1;
	counted_moves(vars);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_exit(vars);
	if (keycode == 119)
	{
		vars->character_direction = 'T';
		move_character(vars, vars->character.pos_y - 1, vars->character.pos_x);
	}
	if (keycode == 97)
	{
		vars->character_direction = 'L';
		move_character(vars, vars->character.pos_y, vars->character.pos_x - 1);
	}
	if (keycode == 115)
	{
		vars->character_direction = 'B';
		move_character(vars, vars->character.pos_y + 1, vars->character.pos_x);
	}
	if (keycode == 100)
	{
		vars->character_direction = 'R';
		move_character(vars, vars->character.pos_y, vars->character.pos_x + 1);
	}
	return (0);
}
