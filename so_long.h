/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:04:10 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/26 14:28:54 by aaudeber         ###   ########.fr       */
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

#define MLX_ERROR 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_image_data {

	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		pos_y;
	int		pos_x;
}	t_image_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		map_y_size;
	int		map_x_size;
	int		is_error;

	t_image_data background;
	t_image_data wall;
	t_image_data collectible;
	t_image_data exit;
	t_image_data character;

}	t_vars;

char	*get_file();
int		open_window(t_vars *vars);
void	setup_image(t_vars *vars);
int		display_image(t_vars *vars);
int		key_press(int keycode, t_vars *vars);

void	free_map(char **map);
void	sizeof_map(t_vars *vars);
void	ft_is_error(char *ptr);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif
