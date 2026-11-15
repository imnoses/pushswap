# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/10/24 16:22:11 by spuschma         #+#    #+#               #
#    Updated: 2026/11/15 23:41:42 by spuschma        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD -MP -I. -I$(LIBFT_DIR)
AR = ar
ARFLAGS = rcs
RM = rm -f


OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS		=	push_swap.c \
				helpers.c \
				parsing.c \
				splitws.c \
				stack.c \
				ops_logic.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)


DEPS = $(OBJS:.o=.d)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT): libft ;

libft:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

compiledb: fclean
	compiledb -n make

-include $(DEPS)

.PHONY: all clean fclean re compiledb libft
