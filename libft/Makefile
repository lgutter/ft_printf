# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/16 14:00:27 by lgutter        #+#    #+#                 #
#    Updated: 2019/09/13 13:22:32 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
include ./Sources

FLGS := -Wall -Wextra -Werror -c
SRCS := $(LFTSOURCES:%= %.c)
OBJS := $(LFTSOURCES:%= %.o)

all: $(NAME)

$(NAME):
	@make objects
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft.a created!"

objects:
	@make norm
	@gcc $(FLGS) $(SRCS)
	@echo "object files compiled!"

clean:
	@rm -rf $(OBJS) *~ \#*# *.zip
	@echo ".o files removed!"

fclean: clean
	@rm -rf $(NAME)
	@echo "libft.a removed!"

re: fclean all

norm:
	@norminette $(SRCS) get_next_line.h libft.h | grep -e "Error" -e "Warning" -B 1 || true
	@echo "Norm checks done!"
