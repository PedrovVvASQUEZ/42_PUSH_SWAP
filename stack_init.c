/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:19:03 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/15 11:53:28 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialisation of the stack taking the final_flash values and convert
// them into longs to then putting them into the t_stack chainlist.

static long	check_viability(char *s)
{
	int		x;
	long	y;

	x = 0;
	y = 0;
	while (s[x] != '\0')
	{
		if (ft_issigns(s[x]))
			x++;
		while (s[x] == '0')
			x++;
		while (s[x] >= '0' && s[x] <= '9')
		{
			x++;
			y++;
		}
	}
	return (y);
}

void	stack_init_a(t_stack **a, char **av)
{
	long	nb;
	int		y;

	y = 0;
	while (av[y] != NULL)
	{
		if (check_viability(av[y]) > 10)
			free_errors(a, av);
		nb = ft_atol(av[y]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_errors(a, av);
		if (check_doubles(*a, (int)nb))
			free_errors(a, av);
		append_node(a, (int)nb);
		y++;
	}
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->data = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
