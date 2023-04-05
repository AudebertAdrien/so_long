/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:05:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/05 15:15:38 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_images(t_vars *vars, t_image_data *img, int pos_x, int pos_y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, pos_x, pos_y);
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

void	free_map(char **map)
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
	mlx_destroy_display(vars->mlx);
	free_map(vars->map);
	free(vars->mlx);
	exit(0);
	return (0);
}
