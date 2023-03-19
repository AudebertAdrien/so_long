/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:00 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/19 15:06:16 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{	
	t_vars	vars;
	char 	*str;
	char	**tab;

	str = get_file();
	printf("\n%s\n", str);

	tab = ft_split(str, '\n');	
	printf("\n=> %p\n", tab);
	printf("END\n");
	ft_free(tab);

	//open_window(&vars);
	//display_image(&vars);
	
	//mlx_key_hook(vars.win, key_press, &vars);
	//mlx_loop(vars.mlx);
	free(str);

	return (0);
}
