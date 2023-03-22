/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/22 12:01:29 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	printf("keycode : %i\n", keycode);
	int i = vars->character.pos_y;
	int j = vars->character.pos_x;

	if (keycode == 65307)
	{
		mlx_destroy_display(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
	}
	if (keycode == 119)
	{
		vars->map[i - 1][j] = vars->map[i][j];
		vars->map[i][j] = '0';
	}
	if (keycode == 97)
	{
		vars->map[i][j - 1] = vars->map[i][j];
		vars->map[i][j] = '0';
	}
	if (keycode == 115)
	{
		vars->map[i + 1][j] = vars->map[i][j];
		vars->map[i][j] = '0';
	}
	if (keycode == 100)
	{
		vars->map[i][j + 1] = vars->map[i][j];
		vars->map[i][j] = '0';
	}
	return (0);
}
