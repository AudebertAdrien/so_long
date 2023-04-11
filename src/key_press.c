/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/11 11:09:17 by aaudeber         ###   ########.fr       */
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

void	move_character(t_vars *vars, int new_y, int new_x)
{
	int		pos_y;
	int		pos_x;

	pos_y = vars->character.pos_y * IMG_RES;
	pos_x = vars->character.pos_x * IMG_RES;
	vars->count_moves += 1;
	if (vars->map[new_y][new_x] == '1')
		return ;
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
	display_images(vars, vars->character.img, new_x * IMG_RES, new_y * IMG_RES);
	counted_moves(vars);
	return ;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_exit(vars);
	if (keycode == 119)
	{
		move_character(vars, vars->character.pos_y - 1, vars->character.pos_x);
		vars->character_direction = 'T';
	}
	if (keycode == 97)
	{
		move_character(vars, vars->character.pos_y, vars->character.pos_x - 1);
		vars->character_direction = 'L';
	}
	if (keycode == 115)
	{
		move_character(vars, vars->character.pos_y + 1, vars->character.pos_x);
		vars->character_direction = 'B';
	}
	if (keycode == 100)
	{
		move_character(vars, vars->character.pos_y, vars->character.pos_x + 1);
		vars->character_direction = 'R';
	}
	return (0);
}
