/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:18:16 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/18 16:30:56 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_doubles_bo(t_stack *a, int nb)
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

void	free_stack_bo(t_stack **stack)
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

void	free_errors_bo(t_stack **a, char **av)
{
	ft_free(av);
	free_stack_bo(a);
	write(1, "Error\n", 6);
	exit(1);
}
