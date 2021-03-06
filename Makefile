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
CC = nasm
NAME = libfts.a

INCDIR = -I ./inc/
OBJDIR = ./obj/

SRC = $(filter %.s, $(shell find src -type f))
OBJ = $(addprefix $(OBJDIR), $(SRC:.s=.o))

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	CFLAGS = -f elf64
	PREFIX = -dLINUX=1
else
	CFLAGS = -f macho64
	PREFIX = --prefix _ -dOSX=1
	#CC = ~/.brew/Cellar/nasm/2.14.02/bin/nasm
 	CC = nasm
endif

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJDIR)%.o: %.s
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(PREFIX) -o $@ $<

install:
	brew install nasm

test: $(NAME)
	make -C ./unittest

clean:
	make -C ./unittest clean
	@rm -rf $(OBJDIR)
	@rm -rf tests

fclean:
	make -C ./unittest fclean
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME) ./tests ./cat
	@rm -rf ./unittest_exec

re: fclean all
