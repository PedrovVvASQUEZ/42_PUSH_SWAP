/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:36:27 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/11 18:19:21 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_fs(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (ft_isalpha(s[x]))
			return (0);
		else if ((ft_issigns(s[x]) && ft_issigns(s[x + 1]))
			|| (ft_issigns(s[x]) && ft_isspace(s[x + 1])))
			return (0);
		x++;
	}
	return (1);
}

static char	*concat(int ac, char **av)
{
	int		y;
	char	*dest;

	if (ac > 2)
	{
		y = 1;
		dest = malloc(sizeof(char*) * y + 1);
		if (!dest)
			return (NULL);
		dest = ft_strjoin(av[y], av[y + 1]);
		y++;
		while ((av[y + 1] != NULL))
		{
			dest = ft_strjoin(dest, av[++y]);
		}
		return (dest);
	}
	return (av[1]);
}

char	**final_flash(int ac, char **av)
{
	char	*fs;
	char	**tab;

	tab = NULL;
	fs = concat(ac, av);
	if (ac == 2 && check_fs(av[1]) == 1)
		tab = ft_split(av[1], ' ');
	else if (ac > 2 && check_fs(fs) == 1)
		tab = ft_split(fs, ' ');
	else
		return (NULL);
	return (tab);
}