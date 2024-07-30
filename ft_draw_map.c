/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:18:49 by marvin            #+#    #+#             */
/*   Updated: 2024/07/30 17:18:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void ft_draw_wall(t_map *info, int *j, int *i)
{
    mlx_put_image_to_window(info->mlx, info->win, 
            info->images->wall, (*j), (*i));
}

void ft_draw_empty(t_map *info, int *j, int *i)
{
    mlx_put_image_to_window(info->mlx, info->win, 
            info->images->empty, (*j), (*i));
}

void ft_draw_player(t_map *info, int *j, int *i)
{
    mlx_put_image_to_window(info->mlx, info->win, 
            info->images->player, (*j), (*i));

    info->y = *i;
    info->x = *j;
}

void ft_draw_map(t_map *info)
{
    int i;
    int j;

    i = 0;
    while (info->map[i])
    {
        j = 0;
        while (info->map[i][j])
        {
            if (info->map[i][j] == '1')
                ft_draw_wall(info, &j, &i);
            else if (info->map[i][j] == '0')
                ft_draw_empty(info, &j, &i);
            else if (info-> map[i][j] == 'P')
                ft_draw_empty(info, &j, &i);
            else if (info->map[i][j] == 'C')
                mlx_put_image_to_window(info->mlx, info->win, 
                        info->images->coin, j * 40, i * 40);
            else if (info->map[i][j] == 'E')
                mlx_put_image_to_window(info->mlx, info->win, 
                        info->images->exit, j * 40, i * 40);
        }
        j++;
    }
    i++;
}