/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:34:56 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/11 18:45:18 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_stack **a, t_stack **b, int median)
{
	if ((*a)->data < median)
		pb(b, a, false);
	else
	{
		pb(b, a, false);
		rb(b, false);
	}
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	while (cheapest_node->index != 0 || cheapest_node->target_node->index != 0)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			rev_rotate_both(a, b, cheapest_node);
		else if (cheapest_node->above_median
			&& !(cheapest_node->target_node->above_median))
			move_a_above_and_b_below_median(a, b, cheapest_node);
		else
			move_a_below_and_b_above_median(a, b, cheapest_node);
	}
	pa(a, b, false);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;
	int	median;

	len_a = stack_len(*a);
	median = ((find_min(*a)->data + find_max(*a)->data) / 2);
	while (len_a-- > 3 && !stack_sorted(*a))
		move_a_to_b(a, b, median);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
