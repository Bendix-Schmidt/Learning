#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bendixschmidt <bendixschmidt@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 16:43:21 by bendixschmi       #+#    #+#              #
#    Updated: 2024/11/14 17:40:10 by bendixschmi      ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# EXECUTABLE NAME
NAME = permutations

# SOURCE FILES
SRCS = permutations.c

# OBJECT FILES
OBJS = $(SRCS:.c=.o)

# COMPILER
CC = gcc

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra -Werror -std=c99

# COMMANDS
RM = rm -f

# RULES
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re