/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:05:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/01 20:09:44 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_duplicate_map(t_vars *vars)
{
	char	**map_cpy;
	int		y;
	int		x;

	y = 0;
	map_cpy = malloc(sizeof(char *) * (vars->map_y_size) + 1);
	if (!map_cpy)
		return (NULL);
	while (y < vars->map_y_size)
	{
		x = 0;
		map_cpy[y] = malloc(sizeof(char) * (vars->map_x_size) + 1);
		if (!map_cpy[y])
			return (NULL);
		while (x < vars->map_x_size)
		{
			map_cpy[y][x] = vars->map[y][x];
			x++;
		}
		map_cpy[y][x] = '\0';
		y++;
	}
	map_cpy[y] = NULL;
	return (map_cpy);
}

int	check_file_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name) - 1;
	return (ft_strncmp(&map_name[len - 3], ".ber", 4));
}

void	ft_is_error(char *ptr)
{
	ft_putstr_fd("Error :\n", 2);
	ft_putstr_fd(ptr, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

void free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_exit(t_vars *vars)	
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->collectible.img);
	mlx_destroy_image(vars->mlx, vars->exit.img);
	mlx_destroy_image(vars->mlx, vars->character.img);
	mlx_destroy_image(vars->mlx, vars->enemy.img);
	mlx_destroy_display(vars->mlx);
	free_map(vars->map);
	free(vars->mlx);
	exit(0);
	return (0);
}

