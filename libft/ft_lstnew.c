/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:55:49 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/17 15:12:32 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nem;

	nem = malloc(sizeof(t_list));
	if (!nem)
		return (NULL);
	nem->content = content;
	nem->next = NULL;
	return (nem);
}
