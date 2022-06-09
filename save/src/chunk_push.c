/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:08:09 by avillar           #+#    #+#             */
/*   Updated: 2022/06/07 15:55:53 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	if_min_or_max(t_swap *swap)
{
	if (swap->bsize > 1 && swap->b[0] < swap->b[1])
		rb(swap);
}

void	go_push(t_swap *swap, int num, int mode)
{
	if (mode == 1)
		while (swap->a[0] != num)
			ra(swap);
	else if (mode == 2)
		while (swap->a[0] != num)
			rra(swap);
	if (swap->a[0] == num)
		pb(swap);
	ft_printf("a = %d\n", swap->b[0]);
	if_min_or_max(swap);
	rrb_inchunk(swap);
	//refresh_minmax(swap, num);
}

void	chunkmax_push(t_swap *swap)
{
	int	x;

	x = 0;
	while (x < swap->chunk->size)
	{
		if (find_nearest_max(swap) == 2)
			go_push(swap, nearest_cmax(swap, 1), 1);
		else if (find_nearest_max(swap) == 4)
			go_push(swap, nearest_cmax(swap, 2), 2);
		x++;
	}
	//swap->chunk->chunk_max--;
	//re_order_chunk(swap, swap->chunk->chunk_max);
}

void	chunkmin_push(t_swap *swap)
{
	int	x;

	x = 0;
	while (x < swap->chunk->size)
	{
		if (find_nearest_min(swap) == 1)
		{
			go_push(swap, nearest_cmin(swap, 1), 1);
		}
		else if (find_nearest_min(swap) == 3)
		{
			go_push(swap, nearest_cmin(swap, 2), 2);
		}
		x++;
	}
	swap->chunk->chunk_min++;
	re_order_chunk_min(swap);
}

void	chunk_pb(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->chunk->size)
	{
		pb(swap);
		i++;
	}
}