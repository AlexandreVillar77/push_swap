/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:52:47 by avillar           #+#    #+#             */
/*   Updated: 2022/03/23 16:50:56 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <stdlib.h>

typedef struct s_swap{
		int		*a;
		int		*b;
		int		size;
		int		ini_size;
}				t_swap;

typedef struct s_split{
        int             i;
        int             j;
        int             len;
} 						t_split;

//fichier utils1.c
int	ft_atoi(const char *str);
void    init_split(t_split *split, const char *s, char c);
int	ft_tablen(char **tab);
t_swap	parse(char *str);
void	init_swap(t_swap *swap, int *a, int size);

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

#endif
