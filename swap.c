/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:42:20 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/11 18:46:55 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	(*head)->previous = NULL;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		write(1, "ss\n", 3);
}
