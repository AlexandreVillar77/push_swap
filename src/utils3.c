/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:06:17 by avillar           #+#    #+#             */
/*   Updated: 2022/03/24 16:33:11 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	*ft_numtabcpy(int *src, int size)
{
	int	i;
	int	*dst;

	i = 0;
	dst = malloc(sizeof(int) * size);
	if (!dst)
		return (0);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	catchmid(int *tab, int size)
{
	return (tab[size / 2]);
}

void	init_chunk(t_swap *swap, int n, int s, int e, int size)
{
	swap->chunk[n].num = n;
	swap->chunk[n].index_s = s;
	swap->chunk[n].index_e = e;
	swap->chunk[n].size = size;
}

void	remalloc_chunk(t_swap *swap, int num)
{
	int		i;
	t_chunk	*chunk;

	i = 0;
	chunk = malloc(sizeof(t_chunk) * num);
}
