/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:52:35 by avillar           #+#    #+#             */
/*   Updated: 2022/03/24 16:02:54 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	main(int argc, char **argv)
{
	t_swap	swap;

	if (argc < 2)
		return (1);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || parse_nodup(&swap) == 1)
		return (1);
	if (is_sorted(swap.a, swap.asize) == 0)
	{
		return (0);
	}
	return (0);
}
