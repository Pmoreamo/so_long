/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:22:38 by pmorello          #+#    #+#             */
/*   Updated: 2024/07/30 11:10:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_read_map(t_map *info)
{
	int fd;
	char *line;

	fd = open(info->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		perror("Error: Archivo vacio\n");
		exit (EXIT_FAILURE);
	}
	while (ft_strlen(line) < info->width -  1)
	{
		info->width++;
	}
	info->height++;
	free(line);
	close (fd);
}

void ft_map_malloc(t_map *info)
{
	char *line;
	int	fd;
	int	i;
	
	fd = open (info->txt, O_RDONLY);
	info->map = (char **)malloc(sizeof(char *) * (info->width + 1));
	line = get_next_line(fd);
	if (!line)
	{
		perror("Archivo vacio");
		exit (EXIT_FAILURE);
	}
	info->map[i] = ft_strdup(line);
	if (!info->map[i])
	{
		perror("Error de memoria");
		exit(EXIT_FAILURE);
	}
	info->map[info->width] = '\0';
	i++;
	free(line);
}
