/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:13:43 by avillar           #+#    #+#             */
/*   Updated: 2022/03/23 16:52:13 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	init_swap(t_swap *swap, int *a, int size)
{
	swap->a = a;
	swap->b = malloc(sizeof(int) * (size + 1));
	if (!swap->b)
		free (swap->a);
	swap->size = size;
	swap->ini_size = size;
}

t_swap	parse(char *str)
{
	int		*res;
	int		i;
	char	**tab;
	t_swap	swap;

	i = 0;
	tab = ft_split(str, ' ');
	res = malloc(sizeof(int) * (ft_tablen(tab) + 1));
	while (tab[i])
	{
		res[i] = ft_atoi(tab[i]);
		i++;
	}
	res[i] = NULL;
	init_swap(&swap, res, ft_tablen(tab));
	free(tab);
	return (swap);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void    init_split(t_split *split, const char *s, char c)
{
        split->i = skipc(s, c, 0);
        split->j = 0;
        split->len = 0;
}

int	ft_atoi(const char *str)
{
	long int		rtn;
	int				nb;

	rtn = 0;
	nb = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		nb = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		rtn *= 10;
		rtn += *str - 48;
		str++;
	}
	return (rtn * nb);
}
