/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:04:53 by mannette          #+#    #+#             */
/*   Updated: 2020/03/03 19:55:26 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorting(t_all *all, int max)
{
	int		max1;
	int		i;
	int		used;

	all->command = NULL;
	used = -1;
	if (max <= 5)
		ft_small(all, max);
	else
	{
		i = 0;
		max1 = ft_sort1(all, max, used);
		while (check(&all->first, &all->second, i) == 0)
		{
			while (all->second)
				max1 = ft_sort2(all, max1, used);
			if (all->first->flag == 0)
				max1 = ft_sort4(all, max);
			else
				max1 = ft_sort3(all);
		}
	}
	ft_double(&all->command);
	return (1);
}

int		ft_sort1(t_all *all, int max, int used)
{
	int	mid;
	int	i;

	i = 0;
	mid = max / 2 + all->next_elem;
	while (all->first->sort_ind != used)
	{
		if ((all->first->sort_ind) <= mid)
		{
			ft_pb(all);
		}
		else
		{
			if (used == -1)
				used = all->first->sort_ind;
			ft_ra(&all->first, &all->command);
		}
	}
	return (mid);
}

int		ft_sort2(t_all *all, int max, int used)
{
	int	mid;

	mid = (max - all->next_elem) / 2 + all->next_elem;
	while ((all->second) && (all->second->sort_ind) != used)
	{
		all->second->flag++;
		if ((all->second->sort_ind) == all->next_elem)
		{
			all->next_elem++;
			all->second->flag = -1;
			ft_pa(&all->first, &all->second, &all->command);
			ft_ra(&all->first, &all->command);
		}
		else if ((all->second->sort_ind) >= mid)
		{
			ft_pa(&all->first, &all->second, &all->command);
		}
		else
		{
			if (used == -1)
				used = all->second->sort_ind;
			ft_rb(&all->second, &all->command);
		}
	}
	return (mid);
}

int		ft_sort3(t_all *all)
{
	int	f;
	int	max;

	max = all->first->sort_ind;
	f = all->first->flag;
	while (f != -1 && all->first->flag == f)
	{
		if (all->first->sort_ind > max)
			max = all->first->sort_ind;
		else if (all->first->sort_ind == all->next_elem)
		{
			all->next_elem++;
			ft_ra(&all->first, &all->command);
		}
		else
			ft_pb(all);
	}
	return (max);
}

int		ft_sort4(t_all *all, int max)
{
	int mid;
	int j;

	j = 0;
	mid = (max - all->next_elem) / 2 + all->next_elem;
	while (all->first->flag != -1)
	{
		all->first->flag++;
		if ((all->first->sort_ind) <= mid)
			ft_pb(all);
		else
		{
			j++;
			ft_ra(&all->first, &all->command);
		}
	}
	while (j > 0)
	{
		ft_rra(&all->first, &all->command);
		j--;
	}
	return (mid);
}
