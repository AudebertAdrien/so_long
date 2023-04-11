/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:26:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/11 14:25:24 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_vars *vars, t_image_data *obj)
{
	obj->img = mlx_xpm_file_to_image(vars->mlx, obj->addr, \
			&obj->img_width, &obj->img_height);
	if (obj->img == NULL)
		free(obj->img);
	return ;
}

void	setup_images(t_vars *vars)
{
	vars->character.addr = "./images/character_front.xpm";
	vars->character_top.addr = "./images/character_top.xpm";
	vars->character_left.addr = "./images/character_left.xpm";
	vars->character_right.addr = "./images/character_right.xpm";
	vars->background.addr = "./images/background.xpm";
	vars->wall.addr = "./images/wall.xpm";
	vars->collectible.addr = "./images/collectible.xpm";
	vars->exit.addr = "./images/exit.xpm";
	file_to_image(vars, &(vars->background));
	file_to_image(vars, &(vars->wall));
	file_to_image(vars, &(vars->collectible));
	file_to_image(vars, &(vars->exit));
	file_to_image(vars, &(vars->character));
	file_to_image(vars, &(vars->character_top));
	file_to_image(vars, &(vars->character_left));
	file_to_image(vars, &(vars->character_right));
	return ;
}
