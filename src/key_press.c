/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/29 17:13:30 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	if (vars->map[y + line][x + column] == 'E')	
		return (1);
	return (0);
}

void	move_character(t_vars *vars, int line, int column)
{
	int y = vars->character.pos_y;
	int x = vars->character.pos_x;
	int exit_y = vars->exit.pos_y;
	int exit_x = vars->exit.pos_x;

	vars->count_moves += 1;
	printf("count: %d\n", vars->count_moves);
	if (vars->map[y + line][x + column] == 'E')
	{
		if(vars->count_collectible == 0)
			ft_exit(vars);
	}
	if (vars->map[y + line][x + column] == '1')
		return ;
	if (vars->map[y + line][x + column] == 'C')	
		vars->count_collectible -= 1;

	vars->map[y + line][x + column] = vars->map[y][x];
	if ((exit_y == y && exit_x == x) && vars->count_collectible != 0)
		vars->map[y][x] = 'E';
	else
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
