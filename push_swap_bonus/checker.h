/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:39 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/23 18:55:07 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// # define INT_MIN -2147483648
// # define INT_MAX 2147483647
// # define LONG_MIN -9223372036854775808
// # define LONG_MAX 9223372036854775807

# include <limits.h>
# include "../pedro_lib/pedro_lib.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				final_index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*previous;
}			t_stack;

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
}			t_vars;

/***************** FUNCTIONS ****************/

char	**final_flash_bo(int ac, char **av);
void	stack_init_a_bo(t_stack **a, char **av);
bool	only_space_bo(char *str);
void	append_node_bo(t_stack **stack, int nbr);

//utils
int		stack_len_bo(t_stack *stack);
void	free_stack_bo(t_stack **stack);
bool	stack_sorted_bo(t_stack *stack);
t_stack	*find_last_bo(t_stack *stack);

//errors
void	free_errors_bo(t_stack **a, char **av);
int		check_doubles_bo(t_stack *a, int nb);

// Commandes 

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif
