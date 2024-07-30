/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:51 by pmorello          #+#    #+#             */
/*   Updated: 2024/07/30 19:16:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 65307
# define W   119
# define A   97
# define S   115
# define D   100


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct images
{
	void	*wall;
	void	*empty;
	void	*exit;
	void	*player;
	void	*coin;
	void	*winner;
} t_images;

typedef struct map
{
	int	x;
	int	y;
	int	height;
	int	width;
	int	player;
	int	count;
	int	finish;
	unsigned int steps;
	char	*txt;
	char	*win;
	char	*mlx;
	char	**map;
	t_images	*images;
} t_map;

typedef struct checker
{
	int coins_left;
	char **map;
} t_checker;

//map
void	ft_read_map(t_map *info);
void	ft_map_malloc(t_map *info);

//check
void	ft_check_format(t_map *info);
void	ft_check_limits(t_map *info);
void	ft_check_inputs(t_map *info);
void	ft_check_map_objects(t_map *info);
void	ft_check_is_posible(t_map *info);

//posible way
void	ft_is_posible(t_map *info, int j, int i, int left);

//draw map
void	ft_draw_map(t_map *info);

//controls
int	ft_controls(int keycode, t_map *info);

//finish
int	ft_exit(t_map *info);
void	ft_game_result(t_map *info);

//utils
int	ft_strlen(char *s);
char	*ft_strdup(const char *s);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_write_itoa(unsigned int n);

#endif