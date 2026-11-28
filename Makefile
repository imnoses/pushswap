# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/10/24 16:22:11 by spuschma         #+#    #+#               #
#    Updated: 2026/11/28 21:53:08 by spuschma        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD -MP -I. -Iinclude -I$(LIBFT_DIR)
AR = ar
ARFLAGS = rcs
RM = rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJ_DIR = obj
SRC_DIR = src

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/ops/ops_logic.c \
			  $(SRC_DIR)/ops/push_swap_ops.c \
			  $(SRC_DIR)/ops/push_swap_reverse_rotate_ops.c \
			  $(SRC_DIR)/ops/push_swap_rotate_ops.c \
			  $(SRC_DIR)/parsing/parsing.c \
			  $(SRC_DIR)/parsing/splitws.c \
			  $(SRC_DIR)/parsing/compute_disorder.c \
			  $(SRC_DIR)/stack/stack.c \
			  $(SRC_DIR)/stack/stack_ops.c \
			  $(SRC_DIR)/utils/helpers.c \
			  $(SRC_DIR)/utils/data.c \
			  $(SRC_DIR)/algos/common/helpers.c \
			  $(SRC_DIR)/algos/selector.c \
			  $(SRC_DIR)/algos/quicky_dp/locations.c \
			  $(SRC_DIR)/algos/quicky_dp/routes.c \
			  $(SRC_DIR)/algos/quicky_dp/chunks.c \
			  $(SRC_DIR)/algos/quicky_dp/quicky_dp.c \
			  $(SRC_DIR)/bench/bench.c \
			  $(SRC_DIR)/ops/ops_table.c


OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS = $(OBJS:.o=.d)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) $(LIBS)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT): libft ;

libft:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

compiledb: fclean
	compiledb -n make

-include $(DEPS)

.PHONY: all clean fclean re compiledb libft
