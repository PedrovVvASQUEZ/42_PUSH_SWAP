/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:06:26 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/21 17:13:48 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*element;

	if (size != 0 && count > (size_t) - 1 / size)
		return (NULL);
	element = malloc(count * size);
	if (!element)
		return (NULL);
	ft_bzero(element, (count * size));
	return (element);
}

/*void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			x;

	x = 0;
	tmp = malloc(sizeof count * size);
	if (!tmp)
		return (NULL);
	while (x < count * size)
	{
		tmp = 0;
		x++;
	}
	return (tmp);
}*/
