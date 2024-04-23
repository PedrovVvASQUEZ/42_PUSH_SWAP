/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:58:45 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/19 16:09:23 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node2push;

	if (*src == NULL)
		return ;
	node2push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	node2push->previous = NULL;
	if (!*dst)
	{
		*dst = node2push;
		node2push->next = NULL;
	}
	else
	{
		node2push->next = *dst;
		node2push->next->previous = node2push;
		*dst = node2push;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
}
