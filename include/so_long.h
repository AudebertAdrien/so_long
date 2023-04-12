/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:04:10 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/12 17:12:07 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <errno.h>

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define IMG_RES 32

typedef struct s_image_data {
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		pos_y;
	int		pos_x;
}	t_image_data;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	char			**map;
	char			**map_cpy;
	int				map_y_size;
	int				map_x_size;
	char			character_direction;
	int				count_moves;
	int				count_collectible;
	int				count_exit;
	int				count_character;
	int				exit_parsed;	
	int				collectible_parsed;
	t_image_data	background;
	t_image_data	wall;
	t_image_data	collectible;
	t_image_data	exit;
	t_image_data	character;
	t_image_data	character_top;
	t_image_data	character_left;
	t_image_data	character_right;
	t_image_data	enemy;
}	t_vars;

char	*get_file(char *map_name);
void	initialize_data(t_vars *vars);
char	**ft_duplicate_map(t_vars *vars);
void	check_map(t_vars *vars);
void	is_exit_reachable(t_vars *vars);
int		open_window(t_vars *vars);
void	setup_images(t_vars *vars);
void	initialize_images(t_vars *vars);
int		key_press(int keycode, t_vars *vars);

void	display_images(t_vars *vars, t_image_data *img, int pos_x, int pos_y);
int		check_file_name(char *map_name);
void	error_message(char *ptr);
void	is_arg_error(char *ptr);
void	is_map_error(t_vars *vars, char *ptr);
void	is_mlx_error(t_vars *vars, char *ptr);
int		ft_exit(t_vars *vars);
void	free_map(char **map);

#endif
