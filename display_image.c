/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/20 18:01:06 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image(t_vars *vars)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, i * 40, j * 40);
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, i * 40, j * 40);
			if (vars->map[i][j] == 'c')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, i * 40, j * 40);
			if (vars->map[i][j] == 'p')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, i * 40, j * 40);
			if (vars->map[i][j] == 'e')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, i * 40, j * 40);
			j++;			
		}
		i++;
	}
	return (0);
}
