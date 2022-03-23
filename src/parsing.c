/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:25:50 by avillar           #+#    #+#             */
/*   Updated: 2022/03/23 16:49:47 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	ft_newsize(t_swap *swap, char c)
{
	int	i;

	i = 0;
	if (c == 'a')
		while (i < swap->size && swap->a[i] != NULL)
			i++;
	else
		while (i < swap->size && swap->b[i] != NULL)
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
	while (i < swap->size)
	{
		x = i + 1;
		while (x < swap->size)
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
