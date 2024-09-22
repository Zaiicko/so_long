/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 03:35:12 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/22 21:49:30 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	loading_all_sprites(t_data *data)
{
	data->sprites.ground = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/ground.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/wall.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/exit.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.exit_open = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/exit_open.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.collec = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/collec.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.player_left = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/player_left.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.player_right = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/player_right.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.player_back = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/player_back.xpm",
		&data->sprites.width, &data->sprites.height);
	data->sprites.player_current = data->sprites.player_back;

	if (!data->sprites.ground || !data->sprites.wall || !data->sprites.exit || !data->sprites.exit_open || !data->sprites.collec || !data->sprites.player_left || !data->sprites.player_right || !data->sprites.player_back)
		error_msg("Loading of sprites failed");
}
