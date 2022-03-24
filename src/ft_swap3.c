/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:54:48 by avillar           #+#    #+#             */
/*   Updated: 2022/03/24 13:01:05 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	rb(t_swap *swap)
{
	int	i;
	int	first;

	i = 0;
	while (i < swap->bsize - 1)
	{
		if (i == 0)
			first = swap->b[i];
		swap->b[i] = swap->b[i + 1];
		i++;
	}
	swap->b[i] = first;
}

void	rr(t_swap *swap)
{
	ra(swap);
	rb(swap);
}

void	rra(t_swap *swap)
{
	int	i;
	int	s;
	int	s2;
	int	last;

	i = 0;
	s = swap->a[i];
	last = swap->a[swap->asize - 1];
	while (i < swap->asize - 1)
	{
		s2 = s;
		s = swap->a[i + 1];
		swap->a[i + 1] = s2;
		i++;
	}
	swap->a[0] = last;
}

void	rrb(t_swap *swap)
{
	int	i;
	int	s;
	int	s2;
	int	last;

	i = 0;
	s = swap->b[i];
	last = swap->b[swap->bsize - 1];
	while (i < swap->bsize - 1)
	{
		s2 = s;
		s = swap->b[i + 1];
		swap->b[i + 1] = s2;
		i++;
	}
	swap->b[0] = last;
}

void	rrr(t_swap *swap)
{
	rra(swap);
	rrb(swap);
}
