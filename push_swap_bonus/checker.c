/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:19:22 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/23 18:56:56 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	visual_stack(t_stack *a, t_stack *b)
{
	printf("[a]	[b]\n");
	while (a || b)
	{
		if (a == NULL)
			printf("-\t");
		else
			printf("{%d}\t", a->data);
		if (b == NULL)
			printf("-\n");
		else
			printf("{%d}\n", b->data);
		if (a)
			a = a->next;
		if (b)
		b = b->next;
	}
	printf("\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}


int	check_move(char *av, t_stack **a, t_stack **b)
{
	if (ft_strcmp(av, "pa\n") == 0)
		return (pa(a, b), 0);
	else if (ft_strcmp(av, "pb\n") == 0)
		return (pb(b, a), 0);
	else if (ft_strcmp(av, "sa\n") == 0)
		return (sa(a), 0);
	else if (ft_strcmp(av, "sb\n") == 0)
		return (sb(b), 0);
	else if (ft_strcmp(av, "ss\n") == 0)
		return (ss(a, b), 0);
	else if (ft_strcmp(av, "ra\n") == 0)
		return (ra(a), 0);
	else if (ft_strcmp(av, "rb\n") == 0)
		return (rb(b), 0);
	else if (ft_strcmp(av, "rr\n") == 0)
		return (rr(a, b), 0);
	else if (ft_strcmp(av, "rra\n") == 0)
		return (rra(a), 0);
	else if (ft_strcmp(av, "rrb\n") == 0)
		return (rrb(b), 0);
	else if (ft_strcmp(av, "rrr\n") == 0)
		return (rrr(a, b), 0);
	return (1);
}

static int	check_av(char **av)
{
	if (av == NULL)
	{
		return (1);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_vars	v;

	v.a = NULL;
	v.b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	av = final_flash_bo(ac, av);
	if (check_av(av))
		return (0);
	stack_init_a_bo(&v.a, av);
	while (1)
	{
		v.line = get_next_line(0, 0);
		if (!v.line)
			break ;
		if (check_move(v.line, &v.a, &v.b))
			return (free_stack_bo(&v.a), free_stack_bo(&v.b), free(v.line)
				, get_next_line(0, 1), write(2, "Error\n", 6));
		free(v.line);
	}
	if (stack_sorted_bo(v.a) && stack_len_bo(v.b) == 0)
		return (free_stack_bo(&v.a), free_stack_bo(&v.b), ft_printf("OK\n"));
	else
		return (free_stack_bo(&v.a), free_stack_bo(&v.b), ft_printf("KO\n"));
}
