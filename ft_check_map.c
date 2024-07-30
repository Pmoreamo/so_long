/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:10:23 by pmorello          #+#    #+#             */
/*   Updated: 2024/07/30 19:17:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_format(t_map *info)
{
	size_t len;

	len = ft_strlen(info->txt);
	if (len < 4 ||ft_strcmp(info->txt + len - 4, ".ber") != 0)
	{
		write(2, "Error\nFormato no valido\n", 20);
		exit (EXIT_FAILURE);
	}
}

void ft_check_limits(t_map *info)
{
	int i;
	int j;
	
	i = 0;
	while (i++ < info->width)
	{
		if (info->map[0][i] != '1' || info->map[info->height - 1][i] != '1')
		{
		
			write(2, "Error\nLimite no valido\n", 20);
			exit(EXIT_FAILURE);
		}	
	}
	j = 0;
	while (j++ < info->height)
	{
		if (info->map[j][0] != '1' || info->map[info->width - 1][j] != '1')
		{
			write(2, "Error\nLimite no valido\n", 20);
			exit(EXIT_FAILURE);
		}
	}
}

void ft_check_inputs(t_map *info)
{
	int i;
	int j;
	
	i = 0;
	while (i++ < info->width)
	{
		j = 0;
		while (j++ < info->height)
		{
			if (info->map[i][j] != '0' && info->map[i][j] != '1'
			&& info->map[i][j] != 'E' && info->map[i][j] != 'P'
			&& info->map[i][j] != 'C')
			{
				write(2,"Error\n Inputs no validos\n", 20);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_check_map_objects(t_map *info)
{
	int	j;
	int	i;
	int	end;

	end = 0;
	j = -1;
	while (info->map[++j])
	{
		i = -1;
		while (info->map[j][++i])
		{
			if (info->map[j][i] == 'P')
				info->player++;
			if (info->map[j][i] == 'C')
				info->count++;
			if (info->map[j][i] == 'E')
				end++;
		}
	}
	if (info->player != 1 || info->count < 1 || end != 1)
	{
		write(2, "Error\nObjetos no validos\n", 21);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_is_posible(t_map *info)
{
	int	i[2];
	int	j[2];
	int	left;

	left = 0;
	i[0] = -1;
	while (info->map[++i[0]])
	{
		i[1] = -1;
		while (info->map[i[0]][++i[1]])
		{
			if (info->map[i[0]][i[1]] == 'P')
			{
				j[0] = i[0];
				j[1] = i[1];
			}
			if (info->map[i[0]][i[1]] == 'E' || info->map[i[0]][i[1]] == 'C')
				left++;
		}
	}
	ft_is_posible(info, j[0], j[1], left);
}