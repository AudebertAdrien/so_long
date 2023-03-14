/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/14 17:40:06 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
#include <stdio.h>
#include <mlx.h>
#include <mlx_int.h>
//#include <X11/X.h>
//#include <X11/keysym.h>

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

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int		ft_close(int keycode, t_vars *vars)
{
	printf("toto");
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{

	printf("%i\n", keycode);
	//mlx_hook(vars.win, 2, 1L<<0, f, &vars); 
	//mlx_key_hook(vars.mlx, ft_close, &vars);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	display_pixel()
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (MLX_ERROR);
	}

	img.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

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
	///////
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);
	//////////////

	//mlx_destroy_window(vars.mlx, vars.win);
	//mlx_destroy_display(vars.mlx);
	//free(vars.mlx);
	return (0);
}


int	main(void)
{	
	//display_pixel();
	display_image();
	return (0);
}
