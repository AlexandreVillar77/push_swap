/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:52:47 by avillar           #+#    #+#             */
/*   Updated: 2022/06/07 15:53:48 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <stdlib.h>

typedef struct s_value{
		int		def_min;
		int		def_max;
		int		min;
		int		max;
}				t_value;

typedef struct s_chunk{
		int		chunk_min;
		int		chunk_max;
		t_value	*cmin;
		t_value	*cmax;
		int		size;
}				t_chunk;

typedef struct s_swap{
		int			*a;
		int			*b;
		int			asize;
		int			bsize;
		int			bini_size;
		long int	b_min_sort;
		int			aini_size;
		int			chunk_size;
		int			a_quartmin;
		t_chunk		*chunk;
}					t_swap;

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
void	ft_swap(int	*a, int *b);
int	*fact_sort(int *tab, int size);

//utils3.c
int	*ft_numtabcpy(int *src, int size);
int	catchmid(int *tab, int size);
int	find_min(int *x, int size);
int	find_min_afsort(int *x, int size);

//is_sorted.c
int	is_sorted(int *tab, int size);
int	is_rev_sorted(int *tab, int size);
int	next_isrevsort(int *tab, int size);
int	next_issorted(int *tab, int size);

//algo_utils1.c
void	push50perto_b(t_swap *swap);
int	find_max(int *x, int size);
int	find_max_afsort(int *x, int size);
int	topa_tob(t_swap *swap, int x);
int	topb_toa(t_swap *swap, int x);

//algo_utils2.c
void	push25_tob(t_swap *swap, int min);
int	find_max_under(int *x, int size, long int top);
int	find_min_under(int *x, int size, long int top);
int	find_quart3(t_swap *swap);
int	find_quart2(t_swap *swap);

//algo_utils3.c
int	find_quart1(t_swap *swap);
int	how_many_min(t_swap *swap, int min);
void	rb_to_rr(t_swap *swap);
void	rrb_to_rrr(t_swap *swap);

//ecart.c
int	find_ecart_min(t_swap *swap);
int	find_ecart_max(t_swap *swap);

//find_near.c
int	find_nearest(t_swap *swap);
int	find_nearest_min(t_swap *swap);
int	find_nearest_max(t_swap *swap);
int	nearest_cmax(t_swap *swap, int m);
int	nearest_cmin(t_swap *swap, int m);

//chunk_data.c
void	refresh_minmax(t_swap *swap, int num);
int	find_max_ofchunk(t_swap *swap, int num);
int	find_min_ofchunk(t_swap *swap, int num);
void	chunk_data_update(t_swap *swap);
void	init_chunk(t_swap *swap);

//chunk_push.c
void	if_min_or_max(t_swap *swap);
void	go_push(t_swap *swap, int num, int mode);
void	chunkmax_push(t_swap *swap);
void	chunkmin_push(t_swap *swap);
void	chunk_pb(t_swap *swap);

//chunk_sort.c
void	re_order_chunk(t_swap *swap, int num);
int		chunk_choice(t_swap *swap);
void	rev_sort_chunks(t_swap *swap);
void	re_order_chunk_min(t_swap *swap);
void	rrb_inchunk(t_swap *swap);


//chunk_check.c
int	chunk_check(t_swap *swap, int size);
int	new_max(t_swap *swap, int size);

#endif