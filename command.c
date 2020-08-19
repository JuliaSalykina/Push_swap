/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:36:14 by mannette          #+#    #+#             */
/*   Updated: 2020/02/20 21:28:42 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** поменять местами первые 2 элемента в a
*/

void	ft_sa(t_push **first, t_com **command)
{
	t_push	*lst;
	t_push	*new;

	if ((*first) && ((*first)->next) != NULL)
	{
		lst = *first;
		new = (*first)->next->next;
		*first = lst->next;
		(*first)->next = lst;
		lst->next = new;
	}
	com(command, "sa\n");
}

/*
** поменять местами первые 2 элемента в b
*/

void	ft_sb(t_push **second, t_com **command)
{
	t_push	*lst2;
	t_push	*new;

	if ((*second) && ((*second)->next) != NULL)
	{
		lst2 = *second;
		new = (*second)->next->next;
		*second = lst2->next;
		(*second)->next = lst2;
		lst2->next = new;
	}
	com(command, "sb\n");
}

/*
** поместить первый элемент стека b в начало стека a
*/

void	ft_pa(t_push **first, t_push **second, t_com **command)
{
	t_push	*lst;
	t_push	*lst2;

	lst2 = *second;
	if (lst2)
	{
		lst = *first;
		*first = lst2;
		*second = lst2->next;
		(*first)->next = lst;
	}
	com(command, "pa\n");
}

/*
** поместить первый элемент стека a в начало стека b
*/

void	ft_pb(t_all *all)
{
	t_push	*lst;
	t_push	*lst2;

	lst = all->first;
	if (!(lst))
		return ;
	else if (all->second == NULL)
	{
		all->second = lst;
		all->first = lst->next;
		all->second->next = NULL;
	}
	else
	{
		lst2 = all->second;
		all->second = lst;
		all->first = lst->next;
		all->second->next = lst2;
	}
	com(&all->command, "pb\n");
}
