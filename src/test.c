/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:20:19 by avillar           #+#    #+#             */
/*   Updated: 2022/03/24 16:23:24 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	algo1(t_swap *swap)
{
	
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
	while (i < swap.asize)
	{
		ft_printf("swap -> a = %d\n", swap.a[i]);
		i++;
	}
	if (is_sorted(swap.a, swap.asize) == 0)
		return (0);
	ft_printf("mid = %d\n", catchmid(fact_sort(swap.a, swap.asize), swap.asize));
	return (0);
}
