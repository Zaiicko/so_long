/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 03:35:12 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/23 03:42:35 by zaiicko          ###   ########.fr       */
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

void	loading_a_sprite(t_data *data, void **sprite, char *path)
{
	*sprite = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&data->sprites.width, &data->sprites.height);
	if (!*sprite)
		error_msg("Loading of sprites failed");
}
