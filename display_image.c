/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/20 16:33:04 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image(t_vars *vars, char **map)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background.img, i * 40, j * 40);
			if (map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, i * 40, j * 40);
			if (map[i][j] == 'c')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible.img, i * 40, j * 40);
			if (map[i][j] == 'p')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->character.img, i * 40, j * 40);
			if (map[i][j] == 'e')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, i * 40, j * 40);
			j++;			
		}
		i++;
	}
	return (0);
}
