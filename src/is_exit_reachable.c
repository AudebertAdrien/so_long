/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exit_reachable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:22 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/31 20:49:54 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_test(char **map, int y, int x)
{
	if (map[y][x] == 'E')
	{
		printf("FOUND!");
		return (1);
	}
	if (map[y][x] == '1')
		return (0);

	map[y][x] = '1';
	if (ft_test(map, y + -1, x))
		return (1);
	if (ft_test(map, y, x + -1))
		return (1);
	if (ft_test(map, y + 1, x))
		return (1);
	if (ft_test(map, y, x + 1))
		return (1);
	return (0);
}

void	is_exit_reachable(t_vars *vars)
{
	int res;
	res = ft_test(vars->map, vars->character.pos_y, vars->character.pos_x);
	printf("res :%d\n", res);
	return ;
}
