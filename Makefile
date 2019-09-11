# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/09/11 13:49:08 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FILES := test.c

HEADER :=

CC := gcc -g -Wall -Wextra -Werror

NAME := hello

all: $(NAME)

assemble:
	@${CC} $(FILES) -o $(NAME)

$(NAME):
	@time make assemble
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m\n"

clean:
	@rm -rf *~ \#*\# .DS_Store
	@echo "\033[0;31mClean succesful!\033[0;00m\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31mObituary of $(NAME): Deceased on $(shell date).\033[0;00m\n"

re: fclean all
