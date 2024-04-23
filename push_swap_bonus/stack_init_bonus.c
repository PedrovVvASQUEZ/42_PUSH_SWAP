/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:19:03 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/19 16:08:21 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	stack_init_a_bo(t_stack **a, char **av)
{
	long	nb;
	int		y;

	y = 0;
	while (av[y] != NULL)
	{
		if (check_viability(av[y]) > 10)
			free_errors_bo(a, av);
		nb = ft_atol(av[y]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_errors_bo(a, av);
		if (check_doubles_bo(*a, (int)nb))
			free_errors_bo(a, av);
		append_node_bo(a, (int)nb);
		y++;
	}
	ft_free(av);
}

void	append_node_bo(t_stack **stack, int nbr)
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
		last_node = find_last_bo(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}
