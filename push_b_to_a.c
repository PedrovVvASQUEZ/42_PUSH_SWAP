/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:57:02 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/11 18:42:11 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b,
			t_stack *cheapest)
{
	while ((cheapest->index != 0 && cheapest->target_node->index != 0))
	{
		rr(a, b, false);
		current_index(*a);
		current_index(*b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			rb(b, false);
			current_index(*b);
		}
	}
	else
	{
		while (cheapest->target_node->index != 0)
		{
			ra(a, false);
			current_index(*a);
		}
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b,
			t_stack *cheapest)
{
	while ((cheapest->index != 0 && cheapest->target_node->index != 0))
	{
		rrr(a, b, false);
		current_index(*a);
		current_index(*b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			rrb(b, false);
			current_index(*b);
		}
	}
	else
	{
		while (cheapest->target_node->index != 0)
		{
			rra(a, false);
			current_index(*a);
		}
	}
}

void	move_a_above_and_b_below_median(t_stack **a, t_stack **b,
			t_stack *cheapest)
{
	while (cheapest->index != 0)
	{
		rb(b, false);
		current_index(*b);
	}
	while (cheapest->target_node->index != 0)
	{
		rra(a, false);
		current_index(*a);
	}
}

void	move_a_below_and_b_above_median(t_stack **a, t_stack **b,
			t_stack *cheapest)
{
	while (cheapest->index != 0)
	{
		rrb(b, false);
		current_index(*b);
	}
	while (cheapest->target_node->index != 0)
	{
		ra(a, false);
		current_index(*a);
	}
}
