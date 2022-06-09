/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:40:17 by avillar           #+#    #+#             */
/*   Updated: 2022/06/07 15:37:21 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	chunk_check(t_swap *swap, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (swap->b[i] == swap->chunk->cmin->max)
			return (1);
		i++;
	}
	return (0);
}

int	new_max(t_swap *swap, int size)
{
	int	i;
	int	max;

	i = swap->chunk->size * (swap->chunk->chunk_min - 1);
	max = swap->b[i];
	while (i < size && swap->b[i] >= swap->chunk->cmin->min
		&& swap->b[i] <= swap->chunk->cmin->max)
	{
		if (swap->b[i] > max)
			max = swap->b[i];
		i++;
	}
	//ft_printf("max = %d\n", max);
	return (max);
}