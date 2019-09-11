# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/09/11 15:55:30 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCES := ft_printf

TESTFILES := tests.c
CSOURCES := $(SOURCES:%= %.c)
OBJECTS := $(SOURCES:%= %.o)

HEADER :=

FLAGS := -Wall -Wextra -Werror -g

NAME := ft_printf

all: $(NAME)

$(NAME):
	@gcc -c -coverage $(FLAGS) $(CSOURCES)
	#@gcc $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m\n"

test: $(NAME)
	@gcc -coverage $(FLAGS) $(TESTFILES) $(OBJECTS) -o test
	@echo "\033[0;32mTest program successfully assembled!\033[0;00m\n"

gcov:
	@gcov $(CSOURCES)

clean:
	@rm -rf $(OBJECTS) *.gcov *.gcno *.gcda *~ \#*\# .DS_Store
	@echo "\033[0;31mClean succesful!\033[0;00m\n"

fclean: clean
	@rm -rf $(NAME) $(TEST)
	@echo "\033[0;31mFinished deleting $(NAME), $(TEST) and other junk on $(shell date).\033[0;00m\n"

re: fclean all
