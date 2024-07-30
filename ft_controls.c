/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:11:10 by marvin            #+#    #+#             */
/*   Updated: 2024/07/30 18:11:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_map *info)
{
	if (info->map[info->y - 1][info->x] != '1'
		&& info->map[info->y - 1][info->x] != 'E')
	{
		if (info->map[info->y - 1][info->x] == 'C'
				|| info->map[info->y - 1][info->x] == '0')
		{
			if (info->map[info->y - 1][info->x] == 'C')
				info->count--;
			info->map[info->y][info->x] = '0';
			info->map[info->y - 1][info->x] = 'P';
		}
		info->y--;
		info->steps++;
		ft_write_itoa(info->steps);
	}
	else if (info->map[info->y - 1][info->x] == 'E'
		&& info->count == 0)
		info->finish = 1;
}

void	move_s(t_map *info)
{
	if (info->map[info->y + 1][info->x] != '1'
		&& info->map[info->y + 1][info->x] != 'E')
	{
		if (info->map[info->y + 1][info->x] == 'C'
				|| info->map[info->y + 1][info->x] == '0')
		{
			if (info->map[info->y + 1][info->x] == 'C')
				info->count--;
			info->map[info->y][info->x] = '0';
			info->map[info->y + 1][info->x] = 'P';
		}
		info->y++;
		info->steps++;
		ft_write_itoa(info->steps);
	}
	else if (info->map[info->y + 1][info->x] == 'E'
		&& info->count == 0)
		info->finish = 1;
}

void	move_a(t_map *info)
{
	if (info->map[info->y][info->x - 1] != '1'
		&& info->map[info->y][info->x - 1] != 'E')
	{
		if (info->map[info->y][info->x - 1] == 'C'
				|| info->map[info->y][info->x - 1] == '0')
		{
			if (info->map[info->y][info->x - 1] == 'C')
				info->count--;
			info->map[info->y][info->x] = '0';
			info->map[info->y][info->x - 1] = 'P';
		}
		info->x--;
		info->steps++;
		ft_write_itoa(info->steps);
	}
	else if (info->map[info->y][info->x - 1] == 'E'
		&& info->count == 0)
		info->finish = 1;
}

void	move_d(t_map *info)
{
	if (info->map[info->y][info->x + 1] != '1'
		&& info->map[info->y][info->x + 1] != 'E')
	{
		if (info->map[info->y][info->x + 1] == 'C'
				|| info->map[info->y][info->x + 1] == '0')
		{
			if (info->map[info->y][info->x + 1] == 'C')
				info->count--;
			info->map[info->y][info->x] = '0';
			info->map[info->y][info->x + 1] = 'P';
		}
		info->x++;
		info->steps++;
		ft_write_itoa(info->steps);
	}
	else if (info->map[info->y][info->x + 1] == 'E'
		&& info->count == 0)
		info->finish = 1;
}

int	ft_controls(int keycode, t_map *info)
{
	if (keycode == ESC)
		ft_exit(info);
	else if (keycode == W && info->finish == 0)
		move_w(info);
	else if (keycode == S && info->finish == 0)
		move_s(info);
	else if (keycode == A && info->finish == 0)
		move_a(info);
	else if (keycode == D && info->finish == 0)
		move_d(info);
	return (0);
}