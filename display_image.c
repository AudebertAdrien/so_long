/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/15 18:03:10 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image()
{
	t_vars			vars;
	t_image_data	background;
	t_image_data	shield;

	background.addr = "./images/test.xpm";
	shield.addr = "./images/bouclier15.xpm";

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (MLX_ERROR);
	}

	background.img = mlx_xpm_file_to_image(vars.mlx, background.addr, &background.img_width, &background.img_height);
	if (background.img == NULL)
	{
		free(background.img);
		return (MLX_ERROR);
	}

	shield.img = mlx_xpm_file_to_image(vars.mlx, shield.addr, &background.img_width, &background.img_height);
	if (shield.img == NULL)
	{
		free(shield.img);
		return (MLX_ERROR);
	}
	
	mlx_put_image_to_window(vars.mlx, vars.win, background.img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, shield.img, 10, 10);

	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);

	return (0);
}


