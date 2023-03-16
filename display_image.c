/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/16 09:09:02 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image(t_vars *vars)
{
	t_image_data	background;
	t_image_data	shield;

	background.addr = "./images/test.xpm";
	shield.addr = "./images/bouclier15.xpm";

	background.img = mlx_xpm_file_to_image(vars->mlx, background.addr, &background.img_width, &background.img_height);
	if (background.img == NULL)
	{
		free(background.img);
		return (MLX_ERROR);
	}

	shield.img = mlx_xpm_file_to_image(vars->mlx, shield.addr, &background.img_width, &background.img_height);
	if (shield.img == NULL)
	{
		free(shield.img);
		return (MLX_ERROR);
	}
	
	mlx_put_image_to_window(vars->mlx, vars->win, background.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, shield.img, 10, 10);
	return (0);
}


