# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astepano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 15:03:21 by astepano          #+#    #+#              #
#    Updated: 2017/10/30 13:01:20 by astepano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = ft_retro
CFLAGS  = -Wall -Wextra -Werror
CC      = clang++


CLASSES = SpaceObject.cpp SpaceShip.cpp Retro.cpp Ncurs.cpp Enemy.cpp Bullet.cpp
HPP     = $(CLASSES:.cpp=.hpp)
SRCS    = $(CLASSES) main.cpp


OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(SRCS) -o $(NAME) -lncurses
	@printf "[CC] %s\n" $(NAME)

.cpp.o:
	@printf "[CC] %s\n" $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "[RM] objects\n"
	@rm -rf $(OBJS)

fclean: clean
	@printf "[RM] %s\n" $(NAME)
	@rm -rf $(NAME)

re: fclean all
