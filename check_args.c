/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:44:51 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/29 19:42:14 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ext(const char *str)
{
	char	*s;
	char	*ext;

	s = (char *)str;
	ext = ".ber";
	while (*s != '\0')
	{
		if (ft_strcmp(s, ext) == 0)
			return (1);
		++s;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("Error: no arguments"), 0);
	if (ac > 2)
		return (ft_printf("Error: too many argument"), 0);
	if (!check_ext(av[1]))
		return (ft_printf("Error: invalid file extension"), 0);
	return (1);
}
