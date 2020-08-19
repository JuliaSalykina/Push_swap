/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:10:15 by mannette          #+#    #+#             */
/*   Updated: 2020/02/20 21:34:11 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** сдвинуть вверх все элементы в стеке a на 1
** первый эелемнт становится последним
*/

void	ft_ra(t_push **first, t_com **command)
{
	t_push	*lst;
	t_push	*last;

	if (*first && ((*first)->next) != NULL)
	{
		last = *first;
		*first = (*first)->next;
		lst = *first;
		while (lst && (lst->next) != NULL)
		{
			lst = lst->next;
		}
		lst->next = last;
		last->next = NULL;
	}
	com(command, "ra\n");
}

/*
** сдвинуть вверх все элементы в стеке b на 1
** первый эелемнт становится последним
*/

void	ft_rb(t_push **second, t_com **command)
{
	t_push *lst2;
	t_push *last;

	if (*second && ((*second)->next) != NULL)
	{
		last = *second;
		*second = (*second)->next;
		lst2 = *second;
		while (lst2 && (lst2->next) != NULL)
		{
			lst2 = lst2->next;
		}
		lst2->next = last;
		last->next = NULL;
	}
	com(command, "rb\n");
}

/*
** сдвинуть вниз все элементы в стеке a на 1
** последний эелемнт становится первым
*/

void	ft_rra(t_push **first, t_com **command)
{
	t_push *lst;
	t_push *begin;

	if (*first && ((*first)->next) != NULL)
	{
		lst = *first;
		begin = *first;
		while (lst && (lst->next->next) != NULL)
		{
			lst = lst->next;
		}
		*first = lst->next;
		(*first)->next = begin;
		lst->next = NULL;
	}
	com(command, "rra\n");
}

/*
** сдвинуть вниз все элементы в стеке b на 1
** последний эелемнт становится первым
*/

void	ft_rrb(t_push **second, t_com **command)
{
	t_push *lst2;
	t_push *begin2;

	if (*second && ((*second)->next) != NULL)
	{
		lst2 = *second;
		begin2 = *second;
		while (lst2 && (lst2->next->next) != NULL)
		{
			lst2 = lst2->next;
		}
		*second = lst2->next;
		(*second)->next = begin2;
		lst2->next = NULL;
	}
	com(command, "rrb\n");
}
