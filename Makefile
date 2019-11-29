# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/11/29 13:02:07 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include Source_files/printfsources
include libft/libftsources
include libft/covsources
include Test_files/testsources

JUNK := **/*~ **/\#*\# **/.DS_Store
COVJUNK := **/*.gcov **/*.gcda *.gcov *.gcda

CSOURCES := $(PRINTFSOURCES:%= Source_files/%.c)
OBJECTS := $(PRINTFSOURCES:%= Source_files/%.o)
GCNOFILES += $(PRINTFSOURCES:%= *.gcno)
LFTOBJECTS := $(LFTSOURCES:%= libft/%.o)
COVOBJECTS := $(COVSOURCES:%= libft/%.o)
GCNOFILES += $(COVSOURCES:%= libft/*.gcno)
COVSOURCES := $(COVSOURCES:%= libft/%.c)
TESTOBJECTS := $(TESTSOURCES:%= Test_files/%.o)
COVJUNK += $(LFTSOURCES:%= libft/%.gcno)
COVJUNK += $(TESTSOURCES:%= Test_files/%.gcno)

LIBRARIES := -lftprintf -lcriterion
LIBRARY_PATH := :$(PWD):$(LIBRARY_PATH)
CPATH := :$(PWD):$(PWD)/libft:$(CPATH)
HEADER := ft_printf.h

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -g
ifdef COV
	CFLAGS += -coverage
endif

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
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(C_OBJECTS)$@ compiled$(C_RESET)"

$(TEST): $(NAME) $(TESTOBJECTS)
	@$(MAKE) norm
	@$(MAKE) clean
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@$(CC) $(TESTOBJECTS) $(CFLAGS) $(LIBRARIES) -o $@
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
	@$(MAKE) fclean -C libft/

re: fclean all

.PHONY: all norm gcov clean oclean fclean re
