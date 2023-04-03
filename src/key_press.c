/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/03 19:15:35 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	is_wall_case(t_vars *vars, int line, int column)
{
	int p_pos_y = vars->character.pos_y;
	int p_pos_x = vars->character.pos_x;

	if (vars->map[p_pos_y + line][p_pos_x + column] == '1')	
		return (1);
	return (0);
}

int	is_exit_case(t_vars *vars, int y_move, int x_move)
{
	int p_pos_y = vars->character.pos_y;
	int p_pos_x = vars->character.pos_x;
	
	if (vars->map[p_pos_y + y_move ][p_pos_x + x_move] == 'E' && vars->count_collectible != 0)	
		return (1);
	return (0);
}
void	move_character(t_vars *vars, int y_move, int x_move)
{
	int p_pos_y = vars->character.pos_y;
	int p_pos_x = vars->character.pos_x;

	vars->count_moves += 1;
	if (vars->map[p_pos_y + y_move][p_pos_x + x_move] == 'E' && vars->count_collectible == 0)
			ft_exit(vars);
	if (vars->map[p_pos_y + y_move][p_pos_x + x_move] == '1')
		return ;
	if (vars->map[p_pos_y + y_move][p_pos_x + x_move] == 'C')	
	{
		vars->count_collectible -= 1;
		vars->map[p_pos_y + y_move][p_pos_x + x_move] = '0'; 
	}

	if (vars->map[p_pos_y + y_move ][p_pos_x + x_move] == 'E' && vars->count_collectible != 0)	
	{
	printf("1");
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, p_pos_x * IMG_RES, p_pos_y * IMG_RES);

		vars->character.pos_y = p_pos_y + y_move; 
		vars->character.pos_x = p_pos_x + x_move; 
		mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, (p_pos_x  + x_move) * IMG_RES, (p_pos_y + y_move) * IMG_RES);
	}
	else
	{
		printf("2");
		vars->character.pos_y = p_pos_y + y_move; 
		vars->character.pos_x = p_pos_x + x_move; 
		mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, (p_pos_x  + x_move) * IMG_RES, (p_pos_y + y_move) * IMG_RES);
	}
	return ;
}
*/

void	move_character(t_vars *vars, int new_y, int new_x)
{
	vars->count_moves += 1;

	//printf("P : (%d,%d)\n", vars->character.pos_y, vars->character.pos_x);
	//printf("coord : (%d,%d)\n", new_y, new_x);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, vars->character.pos_x * IMG_RES, vars->character.pos_y * IMG_RES);
	if (vars->map[vars->character.pos_y][vars->character.pos_x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, vars->character.pos_x * IMG_RES, vars->character.pos_y * IMG_RES);


	vars->character.pos_y = new_y; 
	vars->character.pos_x = new_x; 
	mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, new_x * IMG_RES, new_y * IMG_RES);

	return ;
}

int	key_press(int keycode, t_vars *vars)
{
	printf("keycode : %d\n", keycode);
	if (keycode == 65307)
		ft_exit(vars);
	if (keycode == 119)
		move_character(vars, vars->character.pos_y - 1, vars->character.pos_x);
	if (keycode == 97)
		move_character(vars, vars->character.pos_y, vars->character.pos_x - 1);
	if (keycode == 115)
		move_character(vars, vars->character.pos_y + 1, vars->character.pos_x);
	if (keycode == 100)
		move_character(vars, vars->character.pos_y, vars->character.pos_x + 1);
	return (0);
}

/*
void	move_character(t_vars *vars, int line, int column)
{
	int p_pos_y = vars->character.pos_y;
	int p_pos_x = vars->character.pos_x;
	int exit_y = vars->exit.pos_y;
	int exit_x = vars->exit.pos_x;

	vars->count_moves += 1;

	if (vars->map[p_pos_y + line][p_pos_x + column] == '1')
		return ;
	if (vars->map[p_pos_y + line][p_pos_x + column] == 'C')	
		vars->count_collectible -= 1;
	if (vars->map[p_pos_y + line][p_pos_x + column] == 'E')
	{
		if(vars->count_collectible == 0)
			ft_exit(vars);
	}

	vars->map[p_pos_y + line][p_pos_x + column] = vars->map[p_pos_y][p_pos_x];
	if ((exit_y == p_pos_y && exit_x == p_pos_x) && vars->count_collectible != 0)
		vars->map[p_pos_y][p_pos_x] = 'E';
	else
		vars->map[p_pos_y][p_pos_x] = '0';
}
*/
