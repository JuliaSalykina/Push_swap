/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:04:31 by mannette          #+#    #+#             */
/*   Updated: 2020/03/03 18:36:30 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_all *all, int i)
{
	while (check(&all->first, &all->second, i) == 0)
	{
		if (all->first->sort_ind == i + 2)
			ft_ra(&all->first, &all->command);
		else if (all->first->sort_ind == i || all->first->sort_ind == i + 1)
			ft_sa(&all->first, &all->command);
	}
}

void	ft_four(t_all *all)
{
	int	j;

	j = 1;
	while (all->first->sort_ind != 0)
	{
		ft_ra(&all->first, &all->command);
	}
	ft_pb(all);
	ft_three(all, j);
	ft_pa(&all->first, &all->second, &all->command);
}

void	ft_less(t_all *all)
{
	t_push	*lst;
	int		j;

	lst = all->first;
	j = 0;
	while (lst->sort_ind != 0)
	{
		lst = lst->next;
		j++;
	}
	if (j > 2)
	{
		while (j < 5)
		{
			ft_rra(&all->first, &all->command);
			j++;
		}
	}
}

void	ft_five(t_all *all)
{
	int	j;

	j = 2;
	ft_less(all);
	while (all->next_elem != 2)
	{
		if (all->first->sort_ind == all->next_elem)
		{
			all->next_elem++;
			ft_pb(all);
		}
		else
			ft_ra(&all->first, &all->command);
	}
	ft_three(all, j);
	ft_pa(&all->first, &all->second, &all->command);
	ft_pa(&all->first, &all->second, &all->command);
}

int		ft_small(t_all *all, int max)
{
	int	j;

	if (max == 2)
		ft_sa(&all->first, &all->command);
	else if (max == 3)
	{
		j = 0;
		ft_three(all, j);
	}
	else if (max == 4)
		ft_four(all);
	else if (max == 5)
		ft_five(all);
	return (1);
}
