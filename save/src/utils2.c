/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:21:42 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 11:11:10 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	*remalloc(int *src, int nsize, int bsize)
{
	int	i;
	int	*new;

	i = 0;
	new = malloc(sizeof(int) * (nsize));
	if (!new)
		return (new);
	while (i < nsize && i < bsize)
	{
		new[i] = src[i];
		i++;
	}
	return (new);
}

void	ft_swap(int	*a, int *b)
{
	int	s;
	int s2;

	s = *a;
	s2 = *b;
	*a = s2;
	*b = s;
}

int	*fact_sort(int *tab, int size)
{
	int	*fact;
	int	i;

	fact = ft_numtabcpy(tab, size);
	if (!fact)
		return (0);
	while (is_sorted(fact, size) == 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (fact[i] > fact[i + 1])
				ft_swap(&(fact[i]), &(fact[i + 1]));
			i++;
		}
	}
	return (fact);
}
