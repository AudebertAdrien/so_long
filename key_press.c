/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:37 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/20 12:52:09 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
	}
	if (keycode == 97)
	{
	}
	if (keycode == 115)
	{
	}
	if (keycode == 1000)
	{
	}


	return (0);
}
