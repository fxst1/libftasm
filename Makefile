# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 10:57:23 by fxst1             #+#    #+#              #
#    Updated: 2018/04/13 20:19:55 by fxst1            ###   ########.fr        #
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
endif

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJDIR)%.o: %.s
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

test:
	cc -Wall -Wextra -Werror main.c -o tests -L. -lfts
	cc -Wall -Wextra -Werror cat.c -o cat -L. -lfts

clean:
	@rm -rf $(OBJDIR)
	@rm -rf tests

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)
	@rm -rf tests

re: fclean all
