/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:36:27 by pgrellie          #+#    #+#             */
/*   Updated: 2024/04/23 18:48:50 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_fs(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (!ft_isdigit(s[x]) && !ft_issigns(s[x]) && !ft_isspace(s[x]))
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
	char	*tmp;

	if (ac > 2)
	{
		y = 1;
		dest = malloc(sizeof(char *) * y + 1);
		if (!dest)
			return (free(dest), NULL);
		tmp = dest;
		dest = ft_strjoin(av[y], av[y + 1]);
		free(tmp);
		y++;
		while ((av[y + 1] != NULL))
		{
			tmp = dest;
			dest = ft_strjoin(dest, av[++y]);
			free(tmp);
		}
		return (dest);
	}
	return (av[1]);
}

bool	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

char	**final_flash(int ac, char **av)
{
	char	*fs;
	char	**tab;

	tab = NULL;
	fs = concat(ac, av);
	if (check_fs(fs) == 0)
	{
		write(1, "Error\n", 6);
		return (free(fs), NULL);
	}
	else if (only_space(fs))
	{
		write(1, "Error\n", 6);
		return (free(fs), NULL);
	}
	else if (ac == 2 && check_fs(av[1]) == 1)
		tab = ft_split(av[1], ' ');
	else if (ac > 2 && check_fs(fs) == 1)
	{
		tab = ft_split(fs, ' ');
		free(fs);
	}
	else
		return (NULL);
	return (tab);
}
