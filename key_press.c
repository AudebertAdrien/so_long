/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/22 14:39:27 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_vars *vars, int line, int column)
{
	int i = vars->character.pos_y;
	int j = vars->character.pos_x;

	if (vars->map[i + line][j + column] == '1')	
		return (1);
	return (0);
}

void	move_character(t_vars *vars, int line, int column)
{
	int i = vars->character.pos_y;
	int j = vars->character.pos_x;

	if (!is_wall(vars, line, column))
	{
		vars->map[i + line][j + column] = vars->map[i][j];
		vars->map[i][j] = '0';
	}
}

int	key_press(int keycode, t_vars *vars)
{
	printf("keycode : %i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_display(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
	}

	if (keycode == 119)
		move_character(vars, -1, 0);
	if (keycode == 97)
		move_character(vars, 0, -1);
	if (keycode == 115)
		move_character(vars, 1, 0);
	if (keycode == 100)
		move_character(vars, 0, 1);
	return (0);
}
