/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:16:44 by mannette          #+#    #+#             */
/*   Updated: 2020/03/02 19:29:43 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_com(t_all *all)
{
	t_com	*list;

	list = all->command;
	while (list)
	{
		write(1, list->str, ft_strlen(list->str));
		list = list->next;
	}
	delete_com(all);
}

int		ft_opt(char **n, int str, t_all *all)
{
	int res;
	int j;

	all->opt = NULL;
	all->command = NULL;
	j = 1;
	if (ft_strcmp(n[1], "-n") == 0)
		j++;
	res = ft_valid(n, str, j, all);
	return (res);
}

void	ft_print_num(t_all *all)
{
	t_push	*lst;
	int		n;

	n = 0;
	lst = all->first;
	while (lst)
	{
		n = lst->num;
		ft_putnbr(n);
		write(1, "\n", 1);
		lst = lst->next;
	}
}

void	color(char *s)
{
	if (ft_strcmp(s, "sa\n") == 0)
		write(1, "\e[36msa\e[0m\n", 13);
	if (ft_strcmp(s, "sb\n") == 0)
		write(1, "\e[35msb\e[0m\n", 13);
	if (ft_strcmp(s, "pa\n") == 0)
		write(1, "\e[36mpa\e[0m\n", 13);
	if (ft_strcmp(s, "pb\n") == 0)
		write(1, "\e[35mpb\e[0m\n", 13);
	if (ft_strcmp(s, "ra\n") == 0)
		write(1, "\e[36mra\e[0m\n", 13);
	if (ft_strcmp(s, "rb\n") == 0)
		write(1, "\e[35mrb\e[0m\n", 13);
	if (ft_strcmp(s, "rr\n") == 0)
		write(1, "\e[1;31mrr\e[0m\n", 15);
	if (ft_strcmp(s, "rra\n") == 0)
		write(1, "\e[36mrra\e[0m\n", 14);
	if (ft_strcmp(s, "rrb\n") == 0)
		write(1, "\e[35msrrb\e[0m\n", 14);
	if (ft_strcmp(s, "ss\n") == 0)
		write(1, "\e[1;31mss\e[0m\n", 15);
	if (ft_strcmp(s, "rrr\n") == 0)
		write(1, "\e[1;31mrrr\e[0m\n", 16);
}

void	ft_print_color(t_all *all)
{
	t_com	*lst;

	lst = all->command;
	while (lst)
	{
		color(lst->str);
		lst = lst->next;
	}
	delete_com(all);
}
