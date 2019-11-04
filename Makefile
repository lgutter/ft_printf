# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/11/04 16:29:40 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include Sources
include libft/Sources
include libft/CovSources
include tests/testsources

JUNK := *.gcov *.gcno *.gcda *~ \#*\# .DS_Store

CSOURCES := $(SOURCES:%= %.c)
OBJECTS := $(SOURCES:%= %.o)
LFTOBJECTS := $(LFTSOURCES:%= libft/%.o)
COVOBJECTS := $(COVSOURCES:%= libft/%.o)
COVSOURCES := $(COVSOURCES:%= libft/%.c)
TESTSOURCES := $(TESTNAMES:%= tests/%.c)
TESTOBJECTS := $(TESTNAMES:%= tests/%.o)

LIBRARIES := -lftprintf -lcriterion
INCLUDES := -I ./ -I ./libft -I ./tests
HEADER := ft_printf.h

CC := gcc
CFLAGS := -coverage -Wall -Wextra -Werror -Wunreachable-code -g

NAME := libftprintf.a

TEST := test

C_RESET = \033[0;00m
C_CLEAN = \033[38;5;194m
C_FCLEAN = \033[38;5;156m
C_LIB = \033[38;5;34m
C_TEST = \033[38;5;28m
C_OBJECTS = \033[38;5;220m
C_LINES = \033[38;5;250m

all: $(NAME)

$(NAME): $(LFTOBJECTS) $(COVOBJECTS) $(OBJECTS)
	@$(MAKE) norm
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@ar rc $@ $^
	@ranlib $@
	@echo "$(C_LIB)Libftprintf.a has been compiled$(C_RESET)\n"


%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(C_OBJECTS)$@ compiled$(C_RESET)"

$(TEST): $(NAME) $(TESTOBJECTS)
	@$(MAKE) norm
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@gcc $(CFLAGS) $(INCLUDES) -L ./ $(LIBRARIES) $(TESTOBJECTS) -o $@
	@echo "$(C_TEST)Test program has been compiled$(C_RESET)"

norm:
	@sh checkNorm.sh "$(CSOURCES) $(HEADER)"

gcov:
	@gcov $(CSOURCES) $(COVSOURCES)

clean:
	@rm -rf $(OBJECTS) $(TESTOBJECTS) $(COVOBJECTS) $(JUNK)
	@echo "$(C_CLEAN)Libftprintf object files removed$(C_RESET)"

fclean: clean
	@rm -rf $(NAME) $(TEST)
	@echo "$(C_FCLEAN)Libftprintf.a & test program removed$(C_RESET)"
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@make fclean -C libft/

re: fclean all

.PHONY: all norm gcov clean fclean re
