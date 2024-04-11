/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:54:37 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/11 18:26:30 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->data > (*a)->next->data)
		sa(a, false);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	while (min->index != 0)
	{
		if (min->above_median)
		{
			ra(a, false);
			current_index(*a);
		}
		else
		{
			rra(a, false);
			current_index(*a);
		}
	}
}