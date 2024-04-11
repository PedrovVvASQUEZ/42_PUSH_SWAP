/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:18:16 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/11 18:40:00 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_stack *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->data = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **a)
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
