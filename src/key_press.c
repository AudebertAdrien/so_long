/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/04 17:38:49 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_images(t_vars *vars, t_image_data *img, int pos_x, int pos_y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, pos_x, pos_y);
}

void	move_character(t_vars *vars, int new_y, int new_x)
{
	int pos_y = vars->character.pos_y * IMG_RES;
	int pos_x = vars->character.pos_x * IMG_RES;
	char 			*counted_moves; 
		
	//printf("P : (%d,%d)\n", vars->character.pos_y, vars->character.pos_x);
	//printf("coord : (%d,%d)\n", new_y, new_x);
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

	counted_moves = ft_itoa(vars->count_moves);
	display_images(vars, vars->wall.img, 0,  0); 
	mlx_string_put(vars->mlx, vars->win, 14,  18, 0xFF0000 , counted_moves);
	free(counted_moves);
	return ;
}

int	key_press(int keycode, t_vars *vars)
{
	//printf("keycode : %d\n", keycode);
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
