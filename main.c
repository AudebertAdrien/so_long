/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/16 09:14:34 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{	
	int		fd;
	t_vars	vars;

	fd = open("map/map1.ber", O_RDONLY);
	open_window(&vars);
	//display_pixel();
	display_image(&vars);
	
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
