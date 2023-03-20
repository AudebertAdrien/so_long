/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:26:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/20 15:31:12 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*file_to_image(void *obj)
{
	obj.img = mlx_xpm_file_to_image(vars->mlx, obj.addr, &obj.img_width, &obj.img_height);
	if (background.img == NULL)
	{
		free(background.img);
		return (MLX_ERROR);
	}
	return (obj.img);
}

char	**setup_image()
{
	t_image_data	background;
	t_image_data	wall;
	t_image_data	collectible;
	t_image_data	exit;
	t_image_data	character;

	background.addr = "./images/white.xpm";
	wall.addr = "./images/red.xpm";
	collectible.addr = "./images/yellow.xpm";
	exit.addr = "./images/green.xpm";
	character.addr = "./images/blue.xpm";

	char	*tab[5];
	tab[0] = file_to_image(background.addr);
	tab[1] = file_to_image(wall.addr);
	tab[2] = file_to_image(collectible.addr);
	tab[3] = file_to_image(exit.addr);
	tab[4] = file_to_image(character.addr);

	return (tab);
	/*
	background.img = mlx_xpm_file_to_image(vars->mlx, background.addr, &background.img_width, &background.img_height);
	if (background.img == NULL)
	{
		free(background.img);
		return (MLX_ERROR);
	}
	wall.img = mlx_xpm_file_to_image(vars->mlx, wall.addr, &background.img_width, &background.img_height);
	if (wall.img == NULL)
	{
		free(wall.img);
		return (MLX_ERROR);
	}
	collectible.img = mlx_xpm_file_to_image(vars->mlx, collectible.addr, &background.img_width, &background.img_height);
	if (collectible.img == NULL)
	{
		free(collectible.img);
		return (MLX_ERROR);
	}
	character.img = mlx_xpm_file_to_image(vars->mlx, character.addr, &background.img_width, &background.img_height);
	if (character.img == NULL)
	{
		free(character.img);
		return (MLX_ERROR);
	}
	exit.img = mlx_xpm_file_to_image(vars->mlx, exit.addr, &background.img_width, &background.img_height);
	if (exit.img == NULL)
	{
		free(exit.img);
		return (MLX_ERROR);
	}
	*/
}
