/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:40:14 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/23 05:01:18 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	count_lines(t_data *data, char *name)
{
	int			fd;
	int			i;
	char		*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg("Can't open the map file");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0])
			i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.height = i;
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
