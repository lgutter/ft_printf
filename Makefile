# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/09/13 14:41:49 by ivan-tey      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include Sources
include libft/Sources
include tests/testsources

CSOURCES := $(SOURCES:%= %.c)
OBJECTS := $(SOURCES:%= %.o)
LFTOBJECTS := $(LFTSOURCES:%= libft/%.o)
TESTSOURCES := $(TESTNAMES:%= tests/%.c)

HEADER :=

FLAGS := -Wall -Wextra -Werror -g

NAME := libftprintf.a

TEST := test

all: $(NAME)

$(NAME):
	@echo "- - - - - - - - - -\n\033[0;33mMaking libft object files:\033[0;00m"
	@make objects -C libft/
	@echo "- - - - - - - - - -"
	@gcc -c -coverage $(FLAGS) $(CSOURCES)
	@ar rc $(NAME) $(OBJECTS) $(LFTOBJECTS)
	@ranlib $(NAME)
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m"

$(TEST): $(NAME)
	@gcc -coverage -lcriterion -L ./ -lftprintf $(FLAGS) $(TESTSOURCES) -o $(TEST)
	@echo "\033[0;32mTest program successfully assembled!\033[0;00m"

retest: fclean $(TEST)

gcov:
	@gcov $(CSOURCES)

clean:
	@make clean -C libft/
	@rm -rf $(OBJECTS) *.gcov *.gcno *.gcda *~ \#*\# .DS_Store
	@echo "\033[0;31mClean succesful!\033[0;00m"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) $(TEST)
	@echo "\033[0;31mFinished deleting $(NAME), $(TEST) and other junk on $(shell date).\033[0;00m"

re: fclean all
