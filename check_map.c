/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:49:19 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/24 20:42:46 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *file_name)
{
	int		fd;
	int		row_count;
	char	*line;
	char	*tmp;
	char	*new_tmp;
	char	**map;

	fd = open(file_name, O_RDONLY);
	row_count = 0;
	line = get_next_line(fd);
	tmp = NULL;
	while (line)
	{
		new_tmp = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
		tmp = new_tmp;
		row_count++;
	}
	close(fd);
	if (row_count < 3)
	{
		free(tmp);
		ft_printf("Error: the map requires at least 3 rows");
		return (NULL);
	}
	map = ft_split(tmp, '\n');
	return (map);
}

int	check_map(char *file_name)
{
	char	**map;
	
	map = NULL;
	map = get_map(file_name);
	if (map == NULL)
		return (0);

	return (1);
}