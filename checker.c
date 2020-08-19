/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:21:08 by mannette          #+#    #+#             */
/*   Updated: 2020/03/03 22:33:28 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_line(char *s, t_all *all)
{
	if (ft_strcmp(s, "sa") == 0)
		return (lst_opt(&all->opt, "sa\n", 1));
	if (ft_strcmp(s, "sb") == 0)
		return (lst_opt(&all->opt, "sb\n", 2));
	if (ft_strcmp(s, "pa") == 0)
		return (lst_opt(&all->opt, "pa\n", 3));
	if (ft_strcmp(s, "pb") == 0)
		return (lst_opt(&all->opt, "pb\n", 4));
	if (ft_strcmp(s, "ra") == 0)
		return (lst_opt(&all->opt, "ra\n", 5));
	if (ft_strcmp(s, "rb") == 0)
		return (lst_opt(&all->opt, "rb\n", 6));
	if (ft_strcmp(s, "rr") == 0)
		return (lst_opt(&all->opt, "rr\n", 7));
	if (ft_strcmp(s, "rra") == 0)
		return (lst_opt(&all->opt, "rra\n", 8));
	if (ft_strcmp(s, "rrb") == 0)
		return (lst_opt(&all->opt, "rrb\n", 9));
	if (ft_strcmp(s, "ss") == 0)
		return (lst_opt(&all->opt, "ss\n", 10));
	if (ft_strcmp(s, "rrr") == 0)
		return (lst_opt(&all->opt, "rrr\n", 11));
	return (0);
}

int		read_com(t_all *all)
{
	char	*line;
	int		fd;

	fd = 0;
	while (get_next_line(fd, &line))
	{
		if (check_line(line, all) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

void	do_it2(t_all *all, int i)
{
	if (i == 6)
		ft_rb(&all->second, &all->command);
	if (i == 7)
		ft_rr(all);
	if (i == 8)
		ft_rra(&all->first, &all->command);
	if (i == 9)
		ft_rrb(&all->second, &all->command);
	if (i == 10)
		ft_ss(all);
	if (i == 11)
		ft_rrr(all);
}

int		do_it(t_all *all, char *s)
{
	t_check	*lst;

	lst = all->opt;
	while (lst)
	{
		if (lst->n_com == 1)
			ft_sa(&all->first, &all->command);
		else if (lst->n_com == 2)
			ft_sb(&all->second, &all->command);
		else if (lst->n_com == 3)
			ft_pa(&all->first, &all->second, &all->command);
		else if (lst->n_com == 4)
			ft_pb(all);
		else if (lst->n_com == 5)
			ft_ra(&all->first, &all->command);
		else
			do_it2(all, lst->n_com);
		lst = lst->next;
	}
	if (ft_strcmp(s, "-n") == 0)
		ft_print_num(all);
	if (check_sort(&all->first, &all->second) == 0)
		return (0);
	else
		return (1);
}

int		main(int argc, char **argv)
{
	t_all	all;

	all.first = NULL;
	all.second = NULL;
	if (argc > 1)
	{
		if (ft_opt(argv, argc, &all) == 0 || read_com(&all) == 0)
		{
			write(1, "Error\n", 6);
			return (clean_all(&all));
		}
		else
		{
			if (do_it(&all, argv[1]) == 0)
				write(1, "KO\n", 3);
			else
				write(1, "OK\n", 3);
			clean_all(&all);
		}
	}
	return (0);
}
