/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:25:41 by avillar           #+#    #+#             */
/*   Updated: 2022/06/07 15:54:19 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	re_order_chunk(t_swap *swap, int num)
{
	(void)num;
	int	i;

	while (is_rev_sorted(swap->b, swap->bsize) == 1)
	{
		if (swap->b[0] < swap->b[1] && swap->b[1] != swap->chunk->cmin->def_max)
			sb(swap);
		else
			rb(swap);
		//ft_printf("defmin = %d\n", swap->chunk->cmin->def_min);
		//ft_printf("defmax = %d\n", swap->chunk->cmin->def_max);
		if (swap->bsize > swap->chunk_size && (swap->b[0] < swap->chunk->cmin->def_min || swap->b[0] > swap->chunk->cmin->def_max))
		{
			i = 0;
			while (i < swap->chunk_size && swap->b[0] != swap->chunk->cmin->def_max)
			{
				rrb(swap);
				i++;
			}
		}
	}
}

int		chunk_choice(t_swap *swap)
{
	if (find_nearest(swap) == 1 || find_nearest(swap) == 3)
		return (1);
	else
		return (2);
}

void	rev_sort_chunks(t_swap *swap)
{
	int	i;
	int	num;

	i = 0;
	num = swap->bsize / swap->chunk->size;
	while (i < swap->chunk->size && num > 1)
	{
		rb(swap);
		i++;
	}
}

void	rrb_inchunk(t_swap *swap)
{
	if (swap->b[swap->bsize - 1] >= swap->chunk->cmin->min
		&& swap->b[swap->bsize - 1] <= swap->chunk->cmin->max)
		rrb(swap);
}


void	re_order_chunk_min(t_swap *swap)
{
	int	i;
	int	size;


	int	d;

	d = 0;
	while (d < swap->chunk->size)
	{
		ft_printf("b4 -> %d\n", swap->b[d]);
		d++;
	}
	ft_printf("b4 -> next\n");

	i = swap->chunk->size * (swap->chunk->chunk_min - 1);
	size = swap->chunk->size * swap->chunk->chunk_min;
	while (i < size && is_rev_sorted(swap->b, swap->chunk->size) == 1)
	{
		if (swap->b[0] == swap->chunk->cmin->max)
		{
			pa(swap);
			swap->chunk->cmin->max = new_max(swap, size);
			i++;
			if (size > swap->chunk->size && new_max(swap, size - i) == 0)
				while (i-- > swap->chunk->size * (swap->chunk->chunk_min - 1))
					rrb(swap);
		}
		else if (is_rev_sorted(swap->b, swap->chunk->size) == 1)
			rb(swap);
	}
	chunk_pb(swap);



	d = 0;
	while (d < swap->chunk->size)
	{
		ft_printf("b5 -> %d\n", swap->b[d]);
		d++;
	}
	ft_printf("b5 -> next\n");
}

/*void	re_order_chunk_min(t_swap *swap)
{
	int	i;
	int	size;
	int	x;

	i = swap->chunk->size * (swap->chunk->chunk_min - 1);
	size = swap->chunk->size * swap->chunk->chunk_min;
	x = 0;
	ft_printf("i = %d\n", i);
	ft_printf("size = %d\n", size);
	ft_printf("chunk min = %d\n", swap->chunk->chunk_min);
	int	d;

	d = 0;
	while (d < size)
	{
		ft_printf("b4 -> %d\n", swap->b[d]);
		d++;
	}
	ft_printf("b4 -> next\n");*/
	/*while (size > swap->chunk->size * (swap->chunk->chunk_min - 1))
	{
		ft_printf("b2 -> %d\n", swap->b[0]);
		if (swap->b[0] == swap->chunk->cmin->max)
		{
			x++;
			size--;
			pa(swap);
			ft_printf("pa = %d\n", swap->a[0]);
			swap->chunk->cmin->max = new_max(swap, size);
			while (i > (swap->chunk->size * swap->chunk->chunk_min))
			{
				i--;
				rrb(swap);
			}
		}
		else
			rb(swap);
		i++;
	}
	while (x-- > 0)
		pb(swap);
int	d;

	d = 0;
	while (d < swap->chunk->size * swap->chunk->chunk_min)
	{
		ft_printf("b4 -> %d\n", swap->b[d]);
		d++;
	}
	ft_printf("b4 -> next\n");
}
*/