/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:41 by pmorello          #+#    #+#             */
/*   Updated: 2024/07/30 19:16:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_load_images(t_map *info)
{
	int img_height;
	int img_width;

	info->images = malloc(sizeof(t_images));
	info->images->player = mlx_xpm_file_to_image(info->mlx, 
					"PLAYER", &img_width, &img_height);
	info->images->wall = mlx_xpm_file_to_image(info->mlx, 
					"WALL", &img_width, &img_height);
	info->images->empty = mlx_xpm_file_to_image(info->mlx, 
					"EMPTY", &img_width, &img_height);
	info->images->exit = mlx_xpm_file_to_image(info->mlx, 
					"EXIT", &img_width, &img_height);
	info->images->coin = mlx_xpm_file_to_image(info->mlx, 
					"COIN", &img_width, &img_height);
	info->images->winner = mlx_xpm_file_to_image(info->mlx, 
					"WINNER", &img_width, &img_height);
}

void ft_reset(t_map *info, char *name)
{
	info->x = 0;
	info->y = 0;
	info->height = 0;
	info->width = 0;
	info->player = 0;
	info->count = 0;
	info->steps = 0;
	info->finish = 0;
	info->txt = name;
	ft_load_images(info->images);
}

void ft_check_map(t_map *info)
{
	ft_check_limits(info);
	ft_check_format(info);
	ft_check_inputs(info);
	ft_check_map_objects(info);
	ft_check_is_posible(info);
}

void ft_frame(t_map *info)
{
	mlx_clear_window(info->mlx, info->win);
	ft_draw_map(info);
	if (info->count == 0 && info->player == 1 && info->finish == 1)
		ft_game_result(info);
	return (0);
}

int main(int argc, char **argv)
{
	t_map info;

	if (argc == 2)
	{
		info.mlx = mlx_init();
		ft_reset(&info, argv[1]);
		ft_read_map(&info);
		ft_map_malloc(&info);
		ft_check_map(&info);		
		info.win = mlx_new_window(info.mlx, info.width * 40, 
						info.height * 40,"so_long");
		mlx_hook(info.win, 17, 0, ft_exit, &info);
		mlx_hook(info.win, 02, 0, ft_controls, &info);
		mlx_loop_hook(info.mlx, ft_frame, &info);
		mlx_loop(info.mlx);	
	}
	return (0);
}