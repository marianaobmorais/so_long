/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:44:51 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/06 15:41:45 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_ext(const char *str)
{
	char	*ext;

	ext = ".ber";
	if (ft_strncmp(str + ft_strlen(str) - 4, ext, 4) != 0)
		return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("Error: no arguments\n"), 0);
	if (ac > 2)
		return (ft_printf("Error: too many argument\n"), 0);
	if (!check_ext(av[1]))
		return (ft_printf("Error: invalid file\n"), 0);
	return (1);
}
