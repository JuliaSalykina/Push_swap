/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:32:39 by mannette          #+#    #+#             */
/*   Updated: 2020/02/29 16:38:42 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*new_lst(int n)
{
	t_push	*lst;

	if (!(lst = (t_push*)malloc(sizeof(t_push))))
		return (NULL);
	lst->num = n;
	lst->sort_ind = 0;
	lst->flag = 0;
	lst->next = NULL;
	return (lst);
}

t_push	*create_lst(t_all *all, int n)
{
	t_push	*lst;
	t_push	*new_elem;

	if (!(all->first))
		return (all->first = new_lst(n));
	lst = all->first;
	while (lst)
	{
		if (lst->num == n)
		{
			delete_lst(all);
			return (NULL);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	new_elem = new_lst(n);
	lst->next = new_elem;
	return (new_elem);
}

void	com(t_com **command, char *s)
{
	t_com	*lst;
	t_com	*lst2;

	if (!(*command))
	{
		*command = (t_com*)malloc(sizeof(t_com));
		(*command)->str = s;
		(*command)->next = NULL;
	}
	else
	{
		lst = *command;
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
		lst2 = (t_com *)malloc(sizeof(t_com));
		lst2->str = s;
		lst2->next = NULL;
		lst->next = lst2;
	}
}

int		lst_opt(t_check **opt, char *str, int i)
{
	t_check	*lst;
	t_check	*lst2;

	if (!(*opt))
	{
		*opt = (t_check*)malloc(sizeof(t_check));
		(*opt)->s = str;
		(*opt)->n_com = i;
		(*opt)->next = NULL;
	}
	else
	{
		lst = *opt;
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
		lst2 = (t_check*)malloc(sizeof(t_check));
		lst2->s = str;
		lst2->n_com = i;
		lst2->next = NULL;
		lst->next = lst2;
	}
	return (1);
}
