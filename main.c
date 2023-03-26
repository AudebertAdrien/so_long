/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/26 15:24:27 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{	
	t_vars	vars;
	char 	*line;

	line = get_file(argv[1]);
	printf("\n%s\n", line);
	vars.map = ft_split(line, '\n');
	free(line);
	handle_map(&vars);

	open_window(&vars);
	setup_image(&vars);
	display_image(&vars);
	if (vars.is_error == 1)
		return (0);

	printf("END\n");
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop_hook(vars.mlx, display_image, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
	/*
	void *f;
	void *args;

	f = ft_test;
	args = &vars;

	while (1)
	{
		f(args);
	}
	*/
