/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_posible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:03:24 by marvin            #+#    #+#             */
/*   Updated: 2024/07/30 17:03:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_and_fill(t_checker *c, t_map *info)
{
	int	i;
	int	j;

	c->map = malloc(sizeof(int *) * info->height);
	i = -1;
	while (++i < info->height)
		c->map[i] = malloc(sizeof(int *) * info->width);
	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
			c->map[i][j] = 0;
	}
}

void	free_checker(t_checker *c, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(c->map[i]);
	free(c->map);
	c->map = NULL;
}

void	iter_checker(t_checker *c, t_map *info, int i, int j)
{
	if (c->coins_left == 0)
		return ;
	if (c->map[i][j] == 0 && info->map[i][j] != '1')
	{
		c->map[i][j] = 1;
		if (info->map[i][j] == 'C' || info->map[i][j] == 'E')
			c->coins_left--;
		if (info->map[i][j] == 'E')
			return ;
		iter_checker(c, info, i + 1, j);
		iter_checker(c, info, i - 1, j);
		iter_checker(c, info, i, j + 1);
		iter_checker(c, info, i, j - 1);
	}
}

void	ft_is_posible(t_map *info, int j, int i, int left)
{
	t_checker	c;

	c.coins_left = left;
	malloc_and_fill(&c, info);
	iter_checker(&c, info, j, i);
	if (c.coins_left != 0)
	{
		write(2, "Error\nMap is imposible\n", 23);
		exit(EXIT_FAILURE);
	}
	free_checker(&c, info->height);
}