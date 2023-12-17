# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 11:35:17 by mamazzal          #+#    #+#              #
#    Updated: 2023/12/17 18:52:02 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=magic

SRC= main.cpp
OBJ=$(SRC:.cpp=.o)

CPPFLAGS=-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all