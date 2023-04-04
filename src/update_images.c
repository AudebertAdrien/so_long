/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:14:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/04 14:04:16 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_images(t_vars *vars)
{
	char 			*counted_moves; 

	counted_moves = ft_itoa(vars->count_moves);

	//mlx_string_put(vars->mlx, vars->win, 10, 10, 0x000000 , counted_moves);
	return (0);
}
