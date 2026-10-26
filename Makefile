# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/10/24 16:22:11 by spuschma         #+#    #+#               #
#    Updated: 2026/10/24 23:14:01 by spuschma        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD -MP -I. -I$(LIBFT_DIR)
AR = ar
ARFLAGS = rcs
RM = rm -f


SRC_DIR = src # IS THAT ALLOWED WHEN IT SAYS "*.c"?
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS		= $(SRC_DIR)/push_swap.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


DEPS = $(OBJS:.o=.d)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
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
