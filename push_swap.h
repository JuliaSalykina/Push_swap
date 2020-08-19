/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:40:54 by mannette          #+#    #+#             */
/*   Updated: 2020/03/03 22:34:46 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct		s_com
{
	char			*str;
	struct s_com	*next;
}					t_com;

typedef struct		s_push
{
	int				num;
	int				sort_ind;
	int				flag;
	struct s_push	*next;
}					t_push;

typedef struct		s_check
{
	char			*s;
	int				n_com;
	struct s_check	*next;
}					t_check;

typedef struct		s_all
{
	t_push			*first;
	t_push			*second;
	int				next_elem;
	t_com			*command;
	t_check			*opt;
}					t_all;

int					ft_valid(char **n, int str, int j, t_all *all);

t_push				*create_lst(t_all *all, int n);
void				com(t_com **command, char *s);
int					lst_opt(t_check **opt, char *str, int i);

void				delete_lst(t_all *all);
void				delete_com(t_all *all);
int					clean_all(t_all *all);

void				ft_sa(t_push **first, t_com **command);
void				ft_sb(t_push **second, t_com **command);
void				ft_pa(t_push **first, t_push **second, t_com **command);
void				ft_pb(t_all *all);
void				ft_ra(t_push **first, t_com **command);
void				ft_rb(t_push **second, t_com **command);
void				ft_rra(t_push **first, t_com **command);
void				ft_rrb(t_push **second, t_com **command);
void				ft_ss(t_all *all);
void				ft_rr(t_all *all);
void				ft_rrr(t_all *all);

int					ft_mas_sort(int k, t_all *all);

int					check(t_push **first, t_push **second, int i);
int					check_sort(t_push **first, t_push **second);

int					ft_sorting(t_all *all, int max);
int					ft_sort1(t_all *all, int max, int used);
int					ft_sort2(t_all *all, int max, int used);
int					ft_sort3(t_all *all);
int					ft_sort4(t_all *all, int max);

int					ft_small(t_all *all, int max);

void				ft_double(t_com **command);

void				print_com(t_all *all);

void				ft_option(t_all *all, char *s);
void				ft_print_num(t_all *all);
void				ft_print_color(t_all *all);
int					ft_opt(char **n, int str, t_all *all);

#endif
