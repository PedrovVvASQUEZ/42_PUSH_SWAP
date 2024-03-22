/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:19:22 by pgrellie          #+#    #+#             */
/*   Updated: 2024/03/22 17:53:14 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	av = final_flash(ac, av);
	stack_init_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
// Utiliser turc
	// int		i;
	// i = 0;
	// char **ff;
	// ff = final_flash(ac, av);
	// if (!ff)
	// 	return (0);
	// while (ff[i] != NULL)
	// {
	// 	printf("%s\n", ff[i]);
	// 	i++;
	// }