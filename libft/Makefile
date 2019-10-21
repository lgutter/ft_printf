# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/16 14:00:27 by lgutter        #+#    #+#                 #
#    Updated: 2019/10/12 11:51:24 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
include ./Sources
include ./CovSources

FLGS := -Wall -Wextra -Werror -c -g
SRCS := $(LFTSOURCES:%= %.c)
OBJS := $(LFTSOURCES:%= %.o)
COVSRCS := $(COVSOURCES:%= %.c)
COVOBJS := $(COVSOURCES:%= %.o)

C_RESET = \033[0;00m
C_CLEAN = \033[38;5;159m
C_FCLEAN = \033[38;5;81m
C_OBJECTS = \033[38;5;75m
C_LIB = \033[38;5;33m

all: $(NAME)

$(NAME):
	@make objects
	@ar rc $(NAME) $(OBJS) $(COVOBJS)
	@ranlib $(NAME)
	@echo "$(C_LIB)Libft.a has been compiled$(C_RESET)"

objects: $(COVOBJS) $(OBJS)

$(COVOBJS):
	@gcc $(FLGS) -coverage $(COVSRCS)

$(OBJS):
	@gcc $(FLGS) $(SRCS)
	@echo "$(C_OBJECTS)Libft object files compiled$(C_RESET)"

clean:
	@rm -rf $(OBJS) $(COVOBJS) *.gcov *.gcno *.gcda *~ \#*# *.zip
	@echo "$(C_CLEAN)Libft object files removed$(C_RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(C_FCLEAN)Libft.a removed$(C_RESET)"

re: fclean all
