# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 17:17:48 by pgrellie          #+#    #+#              #
#    Updated: 2024/04/12 18:16:27 by pgrellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### ARGUMENTS ######

NAME =  push_swap
CFLAGS = -g -Wall -Werror -Wextra -g3
ARCHIVE = push_swap.a
COMP = cc
RM = rm -f
MAKE_LIB = ar -rcs

######  SOURCES  ######

SRCS = parsing.c\
		push_swap.c\
		init_b_to_a.c\
		push_b_to_a.c\
		push_command.c\
		rev_rotate.c\
		errors.c\
		rotate.c\
		sort_stacks.c\
		sort_three.c\
		stack_init.c\
		stack_utils.c\
		swap.c\
		
OBJS = $(SRCS:.c=.o)

######   LIBFT   ######

LIBFT_DOSS = libft
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DOSS)
LIBFT_PATH = $(LIBFT_DOSS)/libft.a

######   RULES   ######

all: $(NAME) $(LIBFT_PATH)

$(NAME) : $(ARCHIVE) $(LIBFT_PATH)
	$(COMP) $(ARCHIVE) $(LIBFT_PATH) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o: %.c
	$(COMP) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
	$(LIBFT_MAKE_COMMAND)

clean:
	$(RM) $(OBJS) $(ARCHIVE)
	$(LIBFT_MAKE_COMMAND) clean

fclean: clean
	$(RM) $(NAME)
	$(LIBFT_MAKE_COMMAND) fclean

re: fclean all

.PHONY: all clean fclean re
# NAME = push_swap

# FLAG = -g -Wall -Wextra -Werror
# CC = cc
# RM = rm -rf

# SRC = parsing.c\
#  		push_swap.c\



# OBJ = $(SRC:.c=.o)

# all: $(NAME)

# $(NAME) : $(OBJ)
# 	make -C libft
# 	mv libft /libft.a
# 	$(CC) $(OBJ) -L. -lft -o $(NAME)

# %.o : %.c
# 	$(CC) $(FLAG) -o $@ -c $<

# clean:
# 	make -C libft clean
# 	$(RM) $(OBJ)

# fclean : clean
# 	$(RM) $(NAME) libft.a

# re : fclean all

# .PHONY : all clean fclean re