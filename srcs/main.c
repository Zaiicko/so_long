/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:10:35 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/22 21:36:10 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	loading_map(&data, av[1]);
	hook_managing(&data);
	return (0);
}
