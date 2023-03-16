/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:04:10 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/16 09:08:37 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400
#define MLX_ERROR 1

typedef struct s_pixe_data {

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_pixel_data;

typedef struct s_image_data {

	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
}	t_image_data;



typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;


int		display_pixel();
int		display_image();
int		key_press(int keycode, t_vars *vars);
int		open_window(t_vars *vars);

#endif
