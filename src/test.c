/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:20:19 by avillar           #+#    #+#             */
/*   Updated: 2022/04/11 12:23:03 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	sort_a(t_swap *swap)
{
	int	min;
	int	cut;

	cut = 0;
	while (is_sorted(swap->a, swap->asize) == 1)
	{
		min = find_min(swap->a, swap->asize);
		cut++;
		topa_tob(swap, min);
	}
	while (swap->bsize > 0)
		pa(swap);
}

void	sort_b(t_swap *swap)
{
	int	max;
	int	s;

	s = 0;
	while (s < swap->chunk_size)
	{
		s++;
		max = find_max_under(swap->b, swap->bsize, swap->b_min_sort);
		topb_toa(swap, max);
	}
	while (next_issorted(swap->a, --s) == 0)
		pb(swap);
}

/*****************************************************************
 * algo sort_b apres permier chunk need rb rrb remise en place des valeur
 * apres chaque pa;
 * 
 * 
 * 
 * 
 * ft_printf("min_sort = %d\n", swap->b_min_sort);
 * 
 * 
 * 
 * **************************************************************/
void	algo1(t_swap *swap)
{
	push25_tob(swap, find_quart1(swap));
	sort_b(swap);
	push25_tob(swap, find_quart1(swap));
	swap->b_min_sort = find_max(swap->b, swap->bsize) + 1;
	sort_b(swap);
	push25_tob(swap, find_quart1(swap));
	swap->b_min_sort = find_max(swap->b, swap->bsize) + 1;
	sort_b(swap);
	sort_a(swap);
}

int	main(int argc, char **argv)
{
	int		i;
	t_swap	swap;

	i = -1;
	if (argc < 2)
		return (1);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || parse_nodup(&swap) == 1)
		return (1);
	if (is_sorted(swap.a, swap.asize) == 0)
		return (0);
	algo1(&swap);
	i++;
	/*while (i < swap.asize || i < swap.bsize)
	{
		if (i < swap.asize)
			ft_printf("swap -> a = %d", swap.a[i]);
		if (i < swap.bsize)
		{
			ft_printf("  ||  swap -> b = %d", swap.b[i]);
		}
		ft_printf("\n");
		i++;
	}*/
	return (0);
}
