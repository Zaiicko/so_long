/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 03:35:12 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/24 17:05:31 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	loading_all_sprites(t_data *data)
{
	loading_a_sprite(data, &data->sprites.ground,
		"sprites/ground.xpm");
	loading_a_sprite(data, &data->sprites.player_left,
		"sprites/player_left.xpm");
	loading_a_sprite(data, &data->sprites.player_right,
		"sprites/player_right.xpm");
	loading_a_sprite(data, &data->sprites.player_back,
		"sprites/player_back.xpm");
	loading_a_sprite(data, &data->sprites.exit,
		"sprites/exit.xpm");
	loading_a_sprite(data, &data->sprites.collec,
		"sprites/collec.xpm");
	loading_a_sprite(data, &data->sprites.wall,
		"sprites/wall.xpm");
	loading_a_sprite(data, &data->sprites.exit_open,
		"sprites/exit_open.xpm");
	data->sprites.player_current = data->sprites.player_back;
}

void	destroy_sprites(t_data *data)
{
	if (data->sprites.player_right)
		mlx_destroy_image(data->mlx_ptr, data->sprites.player_right);
	if (data->sprites.player_left)
		mlx_destroy_image(data->mlx_ptr, data->sprites.player_left);
	if (data->sprites.player_back)
		mlx_destroy_image(data->mlx_ptr, data->sprites.player_back);
	if (data->sprites.ground)
		mlx_destroy_image(data->mlx_ptr, data->sprites.ground);
	if (data->sprites.exit)
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit);
	if (data->sprites.collec)
		mlx_destroy_image(data->mlx_ptr, data->sprites.collec);
	if (data->sprites.wall)
		mlx_destroy_image(data->mlx_ptr, data->sprites.wall);
	if (data->sprites.exit_open)
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit_open);
}

void	loading_a_sprite(t_data *data, void **sprite, char *path)
{
	*sprite = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&data->sprites.width, &data->sprites.height);
	if (!*sprite)
	{
		cleanup(data);
		error_msg("Error\nLoading of sprites failed\n");
	}
}
