# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 17:17:48 by pgrellie          #+#    #+#              #
#    Updated: 2024/04/30 15:01:00 by pgrellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### ARGUMENTS ######

NAME =  push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Werror -Wextra
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

BONUS = errors_bonus.c\
			push_command_bonus.c\
			rev_rotate_bonus.c\
			rotate_bonus.c\
			stack_init_bonus.c\
			swap_bonus.c\
			checker.c\
			stack_utils_bonus.c\
			parsing_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:%.c=$(CHECKER_DOSS)/%.o)

######   BONUS   ######

CHECKER_DOSS = push_swap_bonus
CHECKER_PATH = $(CHECKER_DOSS)/$(BONUS_NAME)

######   LIBFT   ######

LIBFT_DOSS = pedro_lib
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DOSS)
LIBFT_PATH = $(LIBFT_DOSS)/pedro_lib.a

######   RULES   ######

all: $(NAME) $(LIBFT_PATH)

$(NAME) : $(ARCHIVE) $(LIBFT_PATH)
	$(COMP) $(CFLAGS) $(ARCHIVE) $(LIBFT_PATH) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o: %.c
	$(COMP) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT_PATH)
	$(COMP) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_PATH) -o $(BONUS_NAME)

$(LIBFT_PATH):
	$(LIBFT_MAKE_COMMAND)

clean:
	$(RM) $(OBJS) $(ARCHIVE)
	$(RM) $(OBJS_BONUS)
	$(LIBFT_MAKE_COMMAND) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(LIBFT_MAKE_COMMAND) fclean

re: fclean all

.PHONY: all clean fclean re
