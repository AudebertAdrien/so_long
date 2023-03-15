/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/15 09:17:54 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image()
{
	t_vars	vars;
	void	*img;
	char	*relative_path = "./images/test.xpm";
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (MLX_ERROR);
	}

	img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	if (img == NULL)
	{
		free(img);
		return (MLX_ERROR);
	}

	struct character
	{
		void *img1;
		void *img2;
	};

	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);

	return (0);
}


