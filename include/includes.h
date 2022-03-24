/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:52:47 by avillar           #+#    #+#             */
/*   Updated: 2022/03/24 16:33:26 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <stdlib.h>

typedef struct s_chunk{
		int		index_s;
		int		index_e;
		int		size;
		int		num;
}				t_chunk;

typedef struct s_swap{
		int		*a;
		int		*b;
		int		asize;
		int		bsize;
		int		aini_size;
		int		chunk_num;
		t_chunk	*chunk;
}				t_swap;

typedef struct s_split{
        int             i;
        int             j;
        int             len;
} 						t_split;

//ft_split.c
int	countcase(char const *s, char c);
int	sizel(char const *s, int i, char c);
void	fill_tab(char const *s, char c, int x, char *dst);
int	skipc(const char *s, char c, int i);
char	**ft_split(char const *s, char c);

//parsing.c
int	parse_check(char *str);
int	parse_nodup(t_swap *swap);
int	ft_newsize(t_swap *swap, char c);

//ft_swap1.c
void	sa(t_swap *swap);
void	sb(t_swap *swap);
void	ss(t_swap *swap);
void	ra(t_swap *swap);
void	pb(t_swap *swap);

//ft_swap2.c
void	pdown_b(t_swap *swap);
void	pdown_a(t_swap *swap);
void	pup_a(t_swap *swap);
void	pup_b(t_swap *swap);
void	pa(t_swap *swap);

//ft_swap3.c
void	rb(t_swap *swap);
void	rr(t_swap *swap);
void	rra(t_swap *swap);
void	rrb(t_swap *swap);
void	rrr(t_swap *swap);

//fichier utils1.c
int	ft_atoi(const char *str);
void    init_split(t_split *split, const char *s, char c);
int	ft_tablen(char **tab);
t_swap	parse(char *str);
void	init_swap(t_swap *swap, int *a, int size);

//utils2.c
int	*remalloc(int *src, int	nsize, int bsize);
int	is_sorted(int *tab, int size);
int	is_rev_sorted(int *tab, int size);
void	ft_swap(int	*a, int *b);
int	*fact_sort(int *tab, int size);

//utils3.c
int	*ft_numtabcpy(int *src, int size);
int	catchmid(int *tab, int size);
void	init_chunk(t_swap *swap, int n, int s, int e, int size);

#endif
