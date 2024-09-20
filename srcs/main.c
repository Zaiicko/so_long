/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:10:35 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/20 03:56:07 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_data data;

	check_args(ac, av);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	loading_all_sprites(&data);
	loading_map(&data, av[1]);
	hook_managing(&data);
	destroy_sprites(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
