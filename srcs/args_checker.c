/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:23:08 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/24 04:34:02 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_args(int ac, char **av)
{
	if (ac < 2)
		error_msg("Error\nNot enough args\n");
	else if (ac > 2)
		error_msg("Error\nToo much args\n");
	else
		if (check_if_ber(av[1]) == 0)
			error_msg("Error\nNeed .ber for the map\n");
}

int	check_if_ber(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len >= 4)
	{
		if (ft_strncmp(&name[len - 4], ".ber", 4) == 0)
			return (1);
	}
	return (0);
}
