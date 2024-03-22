/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:05:35 by pgrellie          #+#    #+#             */
/*   Updated: 2024/03/20 18:24:39 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	current_index(t_stack *stack)
{
	int	x;
	int	median;

	x = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = x;
		if (x <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		x++;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a != NULL)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b != NULL)
		{
			if (current_b->data < a->data
				&& current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analyis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack(b);
	while (a != NULL)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	long	cheapest_data;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_data = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_data = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target(a, b);
	cost_analysis(a, b)
	set_cheapest(a);
}