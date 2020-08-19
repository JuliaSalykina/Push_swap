/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:15:53 by mannette          #+#    #+#             */
/*   Updated: 2020/03/03 22:35:33 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_lst(t_all *all)
{
	t_push *lst;

	if (all->first == NULL)
		return ;
	while ((all->first))
	{
		lst = all->first;
		all->first = all->first->next;
		free(lst);
	}
}

void	delete_lst1(t_all *all)
{
	t_push *lst;

	if (all->second == NULL)
		return ;
	while ((all->second))
	{
		lst = all->second;
		all->second = all->second->next;
		free(lst);
	}
}

void	delete_com(t_all *all)
{
	t_com *lst;

	if (all->command == NULL)
		return ;
	while ((all->command))
	{
		lst = all->command;
		all->command = all->command->next;
		free(lst);
	}
}

void	delete_opt(t_all *all)
{
	t_check *lst;

	if (all->opt == NULL)
		return ;
	while ((all->opt))
	{
		lst = all->opt;
		all->opt = all->opt->next;
		free(lst);
	}
}

int		clean_all(t_all *all)
{
	delete_lst(all);
	delete_lst1(all);
	delete_opt(all);
	delete_com(all);
	return (0);
}
