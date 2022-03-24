/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:25:50 by avillar           #+#    #+#             */
/*   Updated: 2022/03/24 12:43:34 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	ft_newsize(t_swap *swap, char c)
{
	int	i;

	i = 0;
	if (c == 'a')
		while (i < swap->asize)
			i++;
	else
		while (i < swap->bsize)
			i++;
	return (i);
}

int	parse_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != ' '
			&& str[i] != '+')
		{
			ft_printf("Error1\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_nodup(t_swap *swap)
{
	int	i;
	int	x;

	i = 0;
	while (i < swap->asize)
	{
		x = i + 1;
		while (x < swap->asize)
		{
			if (swap->a[i] == swap->a[x])
			{
				ft_printf("Error2\n");
				return (1);
			}
			x++;
		}
		i++;
	}
	return (0);
}
