# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fliraud- <fliraud-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/02 19:08:32 by fran              #+#    #+#              #
#    Updated: 2026/03/03 13:51:58 by fliraud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== BASIC SETUP =====

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs
NAME = push_swap
PRINTF_DIR = printf

# ===== FILE LISTS ====

SRCS = ft_push_swap.c \
		ft_bench.c \
		ft_parse_utils.c \
		ft_parse_utils2.c \
		ft_parse_split.c

OBJS = $(SRCS:.c=.o)

# ===== BUILD RULES =====
# Default command: just type 'make' to build everything
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
# $(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Rule for building any .o file from its .c file
# % is a wildcard: for any file, if you need file.o, build it from file.c
%.o: %.c Makefile ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@

# ===== CLEANUP RULES =====
# Remove all compiled .o files (type 'make clean')
clean:
	rm -f $(OBJS)

# Remove both .o files AND the final program (type 'make fclean')
fclean: clean
	rm -f $(NAME)

# Completely rebuild from scratch (clean + build)
re: fclean all


# ===== COMMANDS =====
# - Make		builds the program creating .o files (all)
# - Make clean		cleans the program removing .o files
# - Make fclean		cleans the program removing .o & libft.a
# - Make re		builds + cleans