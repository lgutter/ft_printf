# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/10/12 11:54:15 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include Sources
include libft/Sources
include libft/CovSources
include tests/testsources

CSOURCES := $(SOURCES:%= %.c)
OBJECTS := $(SOURCES:%= %.o)
LFTOBJECTS := $(LFTSOURCES:%= libft/%.o)
COVOBJECTS := $(COVSOURCES:%= libft/%.o)
COVSOURCES := $(COVSOURCES:%= libft/%.c)
TESTSOURCES := $(TESTNAMES:%= tests/%.c)

LIBRARIES := -lftprintf -lcriterion
INCLUDES := -I ./ -I ./libft -I ./tests
HEADER := ft_printf.h

FLAGS := -coverage -Wall -Wextra -Werror -g

NAME := libftprintf.a

TEST := test

C_RESET = \033[0;00m
C_CLEAN = \033[38;5;194m
C_FCLEAN = \033[38;5;156m
C_LIB = \033[38;5;34m
C_TEST = \033[38;5;28m
C_LINES = \033[38;5;250m

all: $(NAME)

$(NAME):
	@make norm
	@make objects -C libft/
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@gcc -c $(INCLUDES) $(FLAGS) $(CSOURCES)
	@ar rc $(NAME) $(OBJECTS) $(LFTOBJECTS) $(COVOBJECTS)
	@ranlib $(NAME)
	@echo "$(C_LIB)Libftprintf.a has been compiled$(C_RESET)"
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"

$(TEST): $(NAME)
	@make norm
	@gcc $(INCLUDES) -L ./ $(LIBRARIES) $(FLAGS) $(TESTSOURCES) -o $(TEST)
	@echo "$(C_TEST)Test program has been compiled$(C_RESET)"

retest: fclean $(TEST)

norm:
	@sh checkNorm.sh "$(CSOURCES) $(HEADER)"

gcov:
	@gcov $(CSOURCES) $(COVSOURCES)

clean:
	@rm -rf $(OBJECTS) *.gcov *.gcno *.gcda *~ \#*\# .DS_Store
	@echo "$(C_CLEAN)Libftprintf object files removed$(C_RESET)"

fclean: clean
	@rm -rf $(NAME) $(TEST)
	@echo "$(C_FCLEAN)Libftprintf.a & test program removed$(C_RESET)"
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@make fclean -C libft/

re: fclean all
