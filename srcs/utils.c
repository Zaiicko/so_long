/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:40:14 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/19 23:02:32 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_msg(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	count_lines(t_data *data, char *name)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg("Can't open the map file");
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			i++;
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
