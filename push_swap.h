/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:39 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/23 19:33:26 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # define INT_MIN -2147483648
// # define INT_MAX 2147483647
// # define LONG_MIN -9223372036854775808
// # define LONG_MAX 9223372036854775807

# include <limits.h>
# include "pedro_lib/pedro_lib.h"
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

/***************** FUNCTIONS ****************/

char	**final_flash(int ac, char **av);
void	stack_init_a(t_stack **a, char **av);
void	append_node(t_stack **stack, int nbr);
bool	stack_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_last(t_stack *stack);
void	sort_three(t_stack **a);
void	init_nodes(t_stack *a, t_stack *b);
void	cost_analysis(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
bool	only_space(char *str);

//utils
int		stack_len(t_stack *stack);
void	free_stack(t_stack **stack);
void	current_index(t_stack *stack);

t_stack	*get_cheapest(t_stack *stack);

//errors
void	free_errors(t_stack **a, char **av);
int		check_doubles(t_stack *a, int nb);

// Commandes 

void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);

void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

void	sort_stacks(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	sort_three(t_stack **a);

void	rotate_both(t_stack **a, t_stack **b,
			t_stack *cheapest);
void	rev_rotate_both(t_stack **a, t_stack **b,
			t_stack *cheapest);

//asuprmer
void	init_node_b(t_stack *a, t_stack *b);
void	move_a_above_and_b_below_median(t_stack **a, t_stack **b,
			t_stack *cheapest);
void	move_a_below_and_b_above_median(t_stack **a, t_stack **b,
			t_stack *cheapest);

#endif