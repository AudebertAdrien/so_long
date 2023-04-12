/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:18:40 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/12 16:26:27 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *ptr)
{
	ft_putstr_fd("Error :\n", 2);
	ft_putstr_fd(ptr, 2);
	ft_putchar_fd('\n', 2);
}

void	is_arg_error(char *ptr)
{
	error_message(ptr);
	exit(0);
}

void	is_map_error(t_vars *vars, char *ptr)
{
	error_message(ptr);
	free_map(vars->map);
	free_map(vars->map_cpy);
	exit(0);
}

int	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->collectible.img);
	mlx_destroy_image(vars->mlx, vars->exit.img);
	mlx_destroy_image(vars->mlx, vars->character.img);
	mlx_destroy_image(vars->mlx, vars->character_top.img);
	mlx_destroy_image(vars->mlx, vars->character_right.img);
	mlx_destroy_image(vars->mlx, vars->character_left.img);
	mlx_destroy_display(vars->mlx);
	free_map(vars->map);
	free(vars->mlx);
	exit(0);
	return (0);
}

void	is_mlx_error(t_vars *vars, char *ptr)
{
	error_message(ptr);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->collectible.img);
	mlx_destroy_image(vars->mlx, vars->exit.img);
	mlx_destroy_image(vars->mlx, vars->character.img);
	mlx_destroy_image(vars->mlx, vars->character_top.img);
	mlx_destroy_image(vars->mlx, vars->character_right.img);
	mlx_destroy_image(vars->mlx, vars->character_left.img);
	mlx_destroy_display(vars->mlx);
	free_map(vars->map);
	free(vars->mlx);
	exit(0);
}

