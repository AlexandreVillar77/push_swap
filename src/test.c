/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:20:19 by avillar           #+#    #+#             */
/*   Updated: 2022/03/23 16:52:57 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

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
	while (swap.a[i])
	{
		ft_printf("printf = %d\n", swap.a[i]);
		i++;
	}
	/*ft_printf("\nafter :\n");
	sa(&swap);
	i = 0;
	while (i < swap.size)
	{
		ft_printf("printf = %d\n", swap.a[i]);
		i++;
	}*/
	return (0);
}
