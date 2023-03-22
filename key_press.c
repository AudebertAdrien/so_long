/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/22 16:16:25 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_vars *vars)	
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->collectible.img);
	mlx_destroy_image(vars->mlx, vars->exit.img);
	mlx_destroy_image(vars->mlx, vars->character.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->map);
	exit(0);
}

int	is_wall_case(t_vars *vars, int line, int column)
{
	int y = vars->character.pos_y;
	int x = vars->character.pos_x;

	if (vars->map[y + line][x + column] == '1')	
		return (1);
	return (0);
}

int	is_exit_case(t_vars *vars, int line, int column)
{
	int y = vars->character.pos_y;
	int x = vars->character.pos_x;

	if (vars->map[y + line][x + column] == 'e')	
		return (1);
	return (0);
}

void	move_character(t_vars *vars, int line, int column)
{
	int y = vars->character.pos_y;
	int x = vars->character.pos_x;

	if (is_exit_case(vars, line, column))
		ft_exit(vars);
	if (is_wall_case(vars, line, column))
		return ;
	vars->map[y + line][x + column] = vars->map[y][x];
	vars->map[y][x] = '0';
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_exit(vars);
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
