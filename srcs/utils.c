/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:40:14 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/23 19:01:54 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

char	**tab_dup(char **tab, size_t len)
{
	char	**new_tab;
	size_t	i;

	i = 0;
	new_tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_tab)
		return (NULL);
	while (i < len)
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab[i])
			return (ft_free_tab(new_tab), NULL);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

void	cleanup(t_data *data)
{
	destroy_sprites(data);
	ft_free_tab(data->map.map_data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	cleanup_and_exit(t_data *data)
{
	destroy_sprites(data);
	ft_free_tab(data->map.map_data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	error_msg_free_tab(char *msg, char **tab)
{
	write(2, msg, ft_strlen(msg));
	ft_free_tab(tab);
	exit(1);
}
