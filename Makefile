# **************************************************************************** #
# #
# ::: :::::::: #
# Makefile :+: :+: :+: #
# +:+ +:+ +:+ #
# By: cpaquet <marvin@42.fr> +#+ +:+ +#+ #
# +#+#+#+#+#+ +#+ #
# Created: 2017/09/19 17:47:16 by cpaquet#+# #+# #
# Updated: 2018/03/21 17:00:30 by cpaquet ### ########.fr #
# #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

VPATH = 	./libft/ ./printf/ ./GNL/
CPPFLAGS = 	./includes/
SRC_LIBFT = ft_atoi.c ft_lstdelone.c ft_param_to_tab.c ft_sqrt.c ft_strlcat.c \
			ft_strrev.c ft_bzero.c ft_lstiter.c ft_power.c ft_strcat.c \
			ft_strlen.c ft_strsplit.c ft_isalnum.c ft_lstmap.c ft_putchar.c \
			ft_strchr.c ft_strmap.c ft_strstr.c ft_isalpha.c ft_lstnew.c \
			ft_putchar_fd.c ft_strclr.c ft_strmapi.c ft_strsub.c ft_isascii.c \
			ft_memalloc.c ft_putendl.c ft_strcmp.c ft_strncat.c ft_strtrim.c \
			ft_isdigit.c ft_memccpy.c ft_putendl_fd.c ft_strcpy.c ft_strncmp.c \
			ft_tolower.c ft_isprint.c ft_memchr.c ft_putnbr.c ft_strdel.c \
			ft_strncpy.c ft_toupper.c ft_itoa.c ft_memcmp.c ft_putnbr_fd.c \
			ft_strdup.c ft_strndup.c ft_itoa_base.c ft_memcpy.c ft_putstr.c \
			ft_strequ.c ft_strnequ.c ft_itoa_base_char.c ft_memdel.c \
			ft_putstr_fd.c ft_striter.c ft_strnew.c ft_lstadd.c ft_memmove.c \
			ft_sort_integer_table.c ft_striteri.c ft_strnstr.c ft_lstdel.c \
			ft_memset.c ft_split_whitespaces.c ft_strjoin.c ft_strrchr.c \
			ft_lstaddend.c
SRC_GNL =	get_next_line.c
SRC_PRINTF = ft_buffer.c ft_control.c ft_printf.c \
			ptr_c_uni.c ptr_integer.c ptr_pct.c ptr_unsigned.c ft_cast.c \
			ft_len_str_uni.c ft_type.c ptr_char.c ptr_octal.c ptr_string.c \
			ptr_w.c ptr_binary.c ptr_hexa.c ptr_p.c ptr_string_uni.c \
			ft_clean_flags.c ft_precision.c
SRC_NAME =	$(SRC_LIBFT) $(SRC_GNL) $(SRC_PRINTF)
CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
OBJ_PATH =	objs/
OBJ_NAME =	$(SRC_NAME:%.c=%.o)
OBJS =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME): $(OBJS)
	@ echo "\x1B[032m" "-= Objs $(NAME) OK =-" "\x1B[0m"
	@ ar rc $@ $^
	@ ranlib $@
	@ echo "\x1B[032m" "-= $(NAME) OK =-" "\x1B[0m"
	@ echo "---------------------------"

$(OBJ_PATH)%.o : %.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $^ -o $@ -I$(CPPFLAGS)

clean :
	@ rm -rf $(OBJ_PATH)
	@ echo "\x1B[031m" "-= Objs $(NAME) deleted =-" "\x1B[0m"

fclean: clean
	@ rm -f $(NAME)
	@ echo "\x1B[031m" "-= $(NAME) deleted =-" "\x1B[0m"

re : fclean all
