/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:56:14 by mannette          #+#    #+#             */
/*   Updated: 2020/02/25 18:59:19 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check(t_push **first, t_push **second, int i)
{
	t_push	*lst;

	lst = *first;
	if (!(*second) || i > 0)
	{
		while (lst)
		{
			if (lst->sort_ind == i)
			{
				lst = lst->next;
				i++;
			}
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int		check_sort(t_push **first, t_push **second)
{
	t_push	*lst;

	lst = *first;
	if (!(*second))
	{
		while (lst->next != NULL)
		{
			if (lst->num < lst->next->num)
				lst = lst->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
