/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:05:53 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/12 16:18:58 by aaudeber         ###   ########.fr       */
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
