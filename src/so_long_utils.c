/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:05:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:23 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_exit(t_vars *vars)	
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->collectible.img);
	mlx_destroy_image(vars->mlx, vars->exit.img);
	mlx_destroy_image(vars->mlx, vars->character.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->map);
	exit(0);
}

