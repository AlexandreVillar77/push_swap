/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:27:58 by avillar           #+#    #+#             */
/*   Updated: 2022/03/23 16:51:27 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	sa(t_swap *swap)
{
	int	s;

	s = swap->a[0];
	swap->a[0] = swap->a[1];
	swap->a[1] = s;
}

void	sb(t_swap *swap)
{
	int	s;

	s = swap->b[0];
	swap->b[0] = swap->b[1];
	swap->b[1] = s;
}

void	ss(t_swap *swap)
{
	sa(swap);
	sb(swap);
}

void	ra(t_swap *swap, int m)
{
	int	i;
	int	s;
	int	last;

	i = 0;
	while (i < swap->size && swap->a[i] != NULL)
	{
		if (i == 0)
		{
			last = swap->a[swap->size];
			swap->a[swap->size] = swap->a[i];
		}
		i++;
	}
}
