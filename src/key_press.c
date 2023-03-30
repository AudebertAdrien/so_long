/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/30 16:36:49 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall_case(t_vars *vars, int line, int column)
{
	int p_pos_y = vars->character.pos_y;
	int p_pos_x = vars->character.pos_x;

	if (vars->map[p_pos_y + line][p_pos_x + column] == '1')	
		return (1);
	return (0);
}

int	is_exit_case(t_vars *vars, int line, int column)
{
	int p_pos_y = vars->character.pos_y;
	int p_pos_x = vars->character.pos_x;
	
	if (vars->map[p_pos_y + line][p_pos_x + column] == 'E')	
		return (1);
	return (0);
}

void	move_character(t_vars *vars, int line, int column)
{
	int p_pos_y = vars->character.pos_y;
	int p_pos_x = vars->character.pos_x;
	int exit_y = vars->exit.pos_y;
	int exit_x = vars->exit.pos_x;

	vars->count_moves += 1;
	printf("count: %d\n", vars->count_moves);

	if (vars->map[p_pos_y + line][p_pos_x + column] == 'E')
	{
		if(vars->count_collectible == 0)
			ft_exit(vars);
	}
	if (vars->map[p_pos_y + line][p_pos_x + column] == '1')
		return ;
	if (vars->map[p_pos_y + line][p_pos_x + column] == 'C')	
		vars->count_collectible -= 1;

	vars->map[p_pos_y + line][p_pos_x + column] = vars->map[p_pos_y][p_pos_x];
	if ((exit_y == p_pos_y && exit_x == p_pos_x) && vars->count_collectible != 0)
		vars->map[p_pos_y][p_pos_x] = 'E';
	else
		vars->map[p_pos_y][p_pos_x] = '0';
}


int	key_press(int keycode, t_vars *vars)
{
	printf("keycode :%d", keycode);
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
