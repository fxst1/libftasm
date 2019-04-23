# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 10:57:23 by fxst1             #+#    #+#              #
#    Updated: 2019/02/02 18:57:21 by fjacquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = g++
CPPFLAGS = -std=c++11 -Wall -Wextra -Werror -I ./inc/
NAME = libunittest.a
EXEC = ../unittest_exec
INCDIR = -I ./inc/
OBJDIR = ./obj/

SRC = $(filter %.cc, $(shell find src -type f))
OBJ = $(addprefix $(OBJDIR), $(SRC:.cc=.o))

all: $(EXEC)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJDIR)%.o: %.cc
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(EXEC): $(NAME)
	g++ $(CPPFLAGS) -I ../inc -I ./inc ./main.cc -o $(EXEC) -L. -lunittest -L../ -lfts

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(EXEC)

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME) ./$(EXEC)
	@rm -rf tests

re: fclean all
