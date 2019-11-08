# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/11/08 14:27:55 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include Sources
include libft/Sources
include libft/CovSources
include tests/testsources

JUNK := **/*~ **/\#*\# **/.DS_Store
COVJUNK := **/*.gcov **/*.gcda *.gcov *.gcda

CSOURCES := $(SOURCES:%= %.c)
OBJECTS := $(SOURCES:%= %.o)
GCNOFILES += $(SOURCES:%= *.gcno)
LFTOBJECTS := $(LFTSOURCES:%= libft/%.o)
COVOBJECTS := $(COVSOURCES:%= libft/%.o)
GCNOFILES += $(COVSOURCES:%= libft/*.gcno)
COVSOURCES := $(COVSOURCES:%= libft/%.c)
TESTOBJECTS := $(TESTNAMES:%= tests/%.o)
COVJUNK += $(LFTSOURCES:%= libft/%.gcno)
COVJUNK += $(TESTNAMES:%= tests/%.gcno)

LIBRARIES := -lftprintf -lcriterion
LIBRARY_PATH := :$(PWD):$(LIBRARY_PATH)
CPATH := :$(PWD):$(PWD)/libft:$(PWD)/tests:$(CPATH)
HEADER := ft_printf.h

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

$(NAME): $(LFTOBJECTS) $(COVOBJECTS) $(OBJECTS) $(HEADER)
	@$(MAKE) norm
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@ar rc $@ $^
	@ranlib $@
	@echo "$(C_LIB)Libftprintf.a has been compiled$(C_RESET)\n"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(C_OBJECTS)$@ compiled$(C_RESET)"

$(TEST): $(NAME) $(TESTOBJECTS)
	@$(MAKE) norm
	@$(MAKE) clean
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@$(CC) $(CFLAGS) $(LIBRARIES) $(TESTOBJECTS) -o $@
	@echo "$(C_TEST)Test program has been compiled$(C_RESET)"

norm:
	@sh checkNorm.sh "$(CSOURCES) $(HEADER)"

gcov:
	@gcov $(CSOURCES) $(COVSOURCES)

clean:
	@rm -rf $(COVJUNK) $(JUNK)
	@echo "$(C_CLEAN)Junk & coverage files removed$(C_RESET)"

oclean: clean
	@rm -rf $(OBJECTS) $(TESTOBJECTS) $(COVOBJECTS) $(GCNOFILES)
	@echo "$(C_CLEAN)Object files removed$(C_RESET)"

fclean: oclean
	@rm -rf $(NAME) $(TEST)
	@echo "$(C_FCLEAN)$(NAME) & $(TEST) removed$(C_RESET)"
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@make fclean -C libft/

re: fclean all

.PHONY: all norm gcov clean oclean fclean re
