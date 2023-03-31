/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:26:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/31 19:30:32 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_vars *vars, t_image_data *obj)
{
	obj->img = mlx_xpm_file_to_image(vars->mlx, obj->addr, &obj->img_width, &obj->img_height);
	if (obj->img == NULL)
		free(obj->img);
	return ;
}

void	setup_images(t_vars *vars)
{
	vars->background.addr = "./images/white.xpm";
	vars->wall.addr = "./images/red.xpm";
	vars->collectible.addr = "./images/yellow.xpm";
	vars->exit.addr = "./images/green.xpm";
	vars->character.addr = "./images/blue.xpm";
	vars->enemy.addr = "./images/pink.xpm";

	file_to_image(vars, &(vars->background));
	file_to_image(vars, &(vars->wall));
	file_to_image(vars, &(vars->collectible));
	file_to_image(vars, &(vars->exit));
	file_to_image(vars, &(vars->character));
	file_to_image(vars, &(vars->enemy));
	return ;
}
