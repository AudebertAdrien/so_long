/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/04/15 20:33:58 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{	
	t_vars	vars;
	char	*line;

	if (argc != 2)
		is_arg_error("Must be only one argument");
	if (check_file_name(argv[1]))
		is_arg_error("The name of the card must end with .ber");
	line = get_file(argv[1]);
	vars.map = ft_split(line, '\n');
	free(line);
	initialize_data(&vars);
	vars.map_cpy = ft_duplicate_map(&vars);
	check_map(&vars);
	is_exit_reachable(&vars);
	open_window(&vars);
	setup_images(&vars);
	initialize_images(&vars);
	mlx_hook(vars.win, 17, 1L << 0, ft_exit, &vars);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
