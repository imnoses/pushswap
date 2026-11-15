# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/09/13 15:42:53 by spuschma         #+#    #+#               #
#    Updated: 2026/09/17 12:34:02 by spuschma        ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD -MP
DEBUG		?= 0
RM		= rm -f
AR		= ar
ARFLAGS		= rcs

ifeq ($(DEBUG),1)
CFLAGS		+= -g3
CPPFLAGS	+= -DDEBUG=1
endif

SRC_DIR		= .
OBJ_DIR		= obj
SRCS		= $(SRC_DIR)/ft_atoi.c \
			  $(SRC_DIR)/ft_bzero.c \
			  $(SRC_DIR)/ft_calloc.c \
			  $(SRC_DIR)/ft_isalnum.c \
			  $(SRC_DIR)/ft_isalpha.c \
			  $(SRC_DIR)/ft_isascii.c \
			  $(SRC_DIR)/ft_isdigit.c \
			  $(SRC_DIR)/ft_isprint.c \
			  $(SRC_DIR)/ft_itoa.c \
			  $(SRC_DIR)/ft_lstadd_back.c \
			  $(SRC_DIR)/ft_lstadd_front.c \
			  $(SRC_DIR)/ft_lstclear.c \
			  $(SRC_DIR)/ft_lstdelone.c \
			  $(SRC_DIR)/ft_lstiter.c \
			  $(SRC_DIR)/ft_lstlast.c \
			  $(SRC_DIR)/ft_lstmap.c \
			  $(SRC_DIR)/ft_lstnew.c \
			  $(SRC_DIR)/ft_lstsize.c \
			  $(SRC_DIR)/ft_memchr.c \
			  $(SRC_DIR)/ft_memcmp.c \
			  $(SRC_DIR)/ft_memcpy.c \
			  $(SRC_DIR)/ft_memmove.c \
			  $(SRC_DIR)/ft_memset.c \
			  $(SRC_DIR)/ft_putchar_fd.c \
			  $(SRC_DIR)/ft_putendl_fd.c \
			  $(SRC_DIR)/ft_putnbr_fd.c \
			  $(SRC_DIR)/ft_putstr_fd.c \
			  $(SRC_DIR)/ft_split.c \
			  $(SRC_DIR)/ft_strchr.c \
			  $(SRC_DIR)/ft_strdup.c \
			  $(SRC_DIR)/ft_striteri.c \
			  $(SRC_DIR)/ft_strjoin.c \
			  $(SRC_DIR)/ft_strlcat.c \
			  $(SRC_DIR)/ft_strlcpy.c \
			  $(SRC_DIR)/ft_strlen.c \
			  $(SRC_DIR)/ft_strmapi.c \
			  $(SRC_DIR)/ft_strncmp.c \
			  $(SRC_DIR)/ft_strnstr.c \
			  $(SRC_DIR)/ft_strrchr.c \
			  $(SRC_DIR)/ft_strtrim.c \
			  $(SRC_DIR)/ft_substr.c \
			  $(SRC_DIR)/ft_tolower.c \
			  $(SRC_DIR)/ft_toupper.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(RM) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
