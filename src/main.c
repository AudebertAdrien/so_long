/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/31 20:32:33 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{	
	t_vars	vars;
	char 	*line;

	if (argc != 2)
		ft_is_error("Must be only one argument");	
	if (check_file_name(argv[1]))	
		ft_is_error("The name of the card must end with .ber");
	line = get_file(argv[1]);
	printf("\n%s\n", line);
	vars.map = ft_split(line, '\n');
	free(line);

	initialize_data(&vars);
	check_map(&vars);
	open_window(&vars);
	setup_images(&vars);
	display_images(&vars);
	is_exit_reachable(&vars);


	mlx_hook(vars.win, 17, 1L << 0, ft_exit, &vars);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop_hook(vars.mlx, display_images, &vars);
	printf("\nEND\n");
	mlx_loop(vars.mlx);
	return (0);
}
	/*display_images
	void *f;
	void *args;

	f = ft_test;
	args = &vars;

	while (1)
	{
		f(args);
	}
	*/
