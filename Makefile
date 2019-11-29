# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/11 13:40:17 by lgutter        #+#    #+#                 #
#    Updated: 2019/11/29 15:50:01 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include Source_files/printfsources
include libft/libftsources
include libft/covsources

JUNK := **/*~ **/\#*\# **/.DS_Store
COVJUNK := **/*.gcov **/*.gcda *.gcov *.gcda

CSOURCES := $(PRINTFSOURCES:%= Source_files/%.c)
OBJECTS := $(PRINTFSOURCES:%= Source_files/%.o)
LFTOBJECTS := $(LFTSOURCES:%= libft/%.o)
COVOBJECTS := $(COVSOURCES:%= libft/%.o)
COVSOURCES := $(COVSOURCES:%= libft/%.c)

LIBRARIES := -lftprintf -lcriterion
LIBRARY_PATH := :$(PWD):$(LIBRARY_PATH)
CPATH := :$(PWD):$(PWD)/libft:$(CPATH)
HEADER := ft_printf.h

CFLAGS = -Wall -Wextra -Werror

NAME := libftprintf.a

C_RESET = \033[0;00m
C_CLEAN = \033[38;5;194m
C_FCLEAN = \033[38;5;156m
C_LIB = \033[38;5;34m
C_OBJECTS = \033[38;5;220m
C_LINES = \033[38;5;250m

all: $(NAME)

$(NAME): $(LFTOBJECTS) $(COVOBJECTS) $(OBJECTS) $(HEADER)
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@ar rc $@ $^
	@ranlib $@
	@echo "$(C_LIB)Libftprintf.a has been compiled$(C_RESET)\n"


%.o: %.c
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(C_OBJECTS)$@ compiled$(C_RESET)"

clean:
	@rm -rf $(JUNK) $(OBJECTS) $(TESTOBJECTS) $(COVOBJECTS)
	@echo "$(C_CLEAN)Junk & Object files removed$(C_RESET)"

fclean: oclean
	@rm -rf $(NAME)
	@echo "$(C_FCLEAN)$(NAME) removed$(C_RESET)"
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"
	@$(MAKE) fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
