/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/17 17:47:54 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{	
	t_vars	vars;
	char 	*str;
	//char	**tab;

	str = get_file();
	printf("\n%s\n", str);

	printf("END\n");
	
	//tab = ft_split(buf, '\n');	
	//open_window(&vars);
	//display_image(&vars);
	
	//mlx_key_hook(vars.win, key_press, &vars);
	//mlx_loop(vars.mlx);
	free(str);
	//free(tab);
	return (0);
}
