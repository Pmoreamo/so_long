# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 18:52:27 by marvin            #+#    #+#              #
#    Updated: 2024/07/30 18:52:27 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADERS =	so_long.h \
			get_next_line/ get_next_line.h \
			mlx/mlx.h
SRCS = 
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext
RM = rm -rf

all: make_mlx ${NAME}

make_mlx:
			${MAKE} -C mlx

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${MLX_FLAGS} ${OBJS} -o ${NAME}

%o.:%c. Makefile so_long.h
		${CC} ${CFLAGS} -c $< -o $@

clean: 
		${RM} ${OBJS}
		${MAKE} -C mlx clean

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re