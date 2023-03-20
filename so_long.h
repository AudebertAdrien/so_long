/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:04:10 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/20 15:28:31 by aaudeber         ###   ########.fr       */
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

#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 200
#define MLX_ERROR 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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

char	*get_file();
int		open_window(t_vars *vars);
int		display_image();
int		key_press(int keycode, t_vars *vars);
char	**setup_image();

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif
