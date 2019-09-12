#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/16 14:00:27 by lgutter       #+#    #+#                  #
#    Updated: 2019/09/11 16:43:45 by lgutter       ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME := libft.a
SRCN := ft_memset \
ft_bzero \
ft_memcpy \
ft_memccpy \
ft_memmove \
ft_memchr \
ft_memcmp \
ft_strlen \
ft_strdup \
ft_strcpy \
ft_strncpy \
ft_strcat \
ft_strncat \
ft_strlcat \
ft_strchr \
ft_strrchr \
ft_strstr \
ft_strnstr \
ft_strcmp \
ft_strncmp \
ft_atoi \
ft_isalpha \
ft_isdigit \
ft_isalnum \
ft_isascii \
ft_isprint \
ft_toupper \
ft_tolower \
ft_memalloc \
ft_memdel \
ft_strnew \
ft_strdel \
ft_strclr \
ft_striter \
ft_striteri \
ft_strmap \
ft_strmapi \
ft_strequ \
ft_strnequ \
ft_strsub \
ft_strjoin \
ft_strtrim \
ft_strsplit \
ft_itoa \
ft_putchar \
ft_putstr \
ft_putendl \
ft_putnbr \
ft_putchar_fd \
ft_putstr_fd \
ft_putendl_fd \
ft_putnbr_fd \
ft_lstnew \
ft_lstdelone \
ft_lstdel \
ft_lstadd \
ft_lstiter \
ft_lstmap \
ft_absneg \
ft_abspos \
ft_iswhitespace \
ft_strlenc \
ft_memrcpy \
ft_memdup \
ft_memcdup \
ft_memjoin \
ft_memexpand \
ft_memdelsize \
ft_nbrlenbase \
ft_lstlen \
ft_lstaddback \
ft_lstaddnext

FLGS := -Wall -Wextra -Werror -c
SRCS := $(SRCN:%= %.c)
OBJS := $(SRCN:%= %.o)

all: $(NAME)

$(NAME):
	@make norm
	@gcc $(FLGS) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft.a created!"

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
