/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/14 16:31:28 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
#include <stdio.h>
#include <mlx.h>
#include <mlx_int.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400
#define MLX_ERROR 1


typedef struct s_data {

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	display_pixel()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (mlx == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return (MLX_ERROR);
	}

	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

int	display_image()
{
	void	*mlx;
	void	*img;
	void	*img2;
	void	*mlx_win;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;
	int		t;

	mlx = mlx_init();
	if (mlx == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return (MLX_ERROR);
	}
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	if (img == NULL)
	{
		free(img);
		return (MLX_ERROR);
	}
	mlx_loop(mlx);

	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}

int	main(void)
{	
	//display_pixel();
	display_image();
	return (0);
}
