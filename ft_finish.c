/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:04:09 by marvin            #+#    #+#             */
/*   Updated: 2024/07/30 18:04:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_map *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

void	ft_game_result(t_map *info)
{
	mlx_clear_window(info->mlx, info->win);
	mlx_put_image_to_window(info->mlx, info->win, info->images->winner,
			info->width * 40 / 2.4, info->height * 40 / 4);
}