/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exit_reachable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:22 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/01 19:38:06 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_vars *vars, int y, int x)
{
	if (vars->exit_parsed == 1 && vars->collectible_parsed == vars->count_collectible)
		return (1); 
	if (vars->map_cpy[y][x] == 'E')
	{
		vars->exit_parsed = 1;
		return (0);
	}
	if (vars->map_cpy[y][x] == '1')
		return (0);
	if (vars->map_cpy[y][x] == 'C')
		vars->collectible_parsed += 1;

	vars->map_cpy[y][x] = '1';
	if (parse_map(vars, y + -1, x))
		return (1);
	if (parse_map(vars, y, x + -1))
		return (1);
	if (parse_map(vars, y + 1, x))
		return (1);
	if (parse_map(vars, y, x + 1))
		return (1);
	return (0);
}

void	is_exit_reachable(t_vars *vars)
{
	int res;

	res = parse_map(vars, vars->character.pos_y, vars->character.pos_x);
	if (!res)
		ft_is_error("Pathfinding isn't reachable");
	else
		printf("Is reachable");
	return ;
}
