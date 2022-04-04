/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:20:19 by avillar           #+#    #+#             */
/*   Updated: 2022/04/04 16:12:28 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	sort_a(t_swap *swap)
{
	int	i;
	int	min;

	while (is_sorted(swap->a, swap->asize) == 1)
	{
		i = 0;
		min = find_min_afsort(swap->a, swap->asize);
		while (i < swap->asize)
		{
			if (swap->a[i] > min)
				pb(swap);
			i++;
		}
	}
}

void	algo1(t_swap *swap)
{
	push50perto_b(swap);
}

int	main(int argc, char **argv)
{
	int		i;
	t_swap	swap;

	i = 0;
	if (argc < 2)
		return (1);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || parse_nodup(&swap) == 1)
		return (1);
	if (is_sorted(swap.a, swap.asize) == 0)
		return (0);
//	ft_printf("mid = %d\n", catchmid(fact_sort(swap.a, swap.asize), swap.asize));
	algo1(&swap);
	while (i < swap.asize)
	{
		ft_printf("swap -> a = %d", swap.a[i]);
		if (i < swap.bsize)
		{
			ft_printf("  ||  swap -> b = %d", swap.b[i]);
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("a max = %d\n", find_max(swap.a, swap.asize));
	return (0);
}
