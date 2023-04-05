/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:57:26 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/05 14:58:14 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_duplicate_map(t_vars *vars)
{
	char	**map_cpy;
	int		y;
	int		x;

	y = 0;
	map_cpy = malloc(sizeof(char *) * (vars->map_y_size + 1));
	if (!map_cpy)
		return (NULL);
	while (y < vars->map_y_size)
	{
		x = 0;
		map_cpy[y] = malloc((sizeof(char) * (vars->map_x_size)) + 1);
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
