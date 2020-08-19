/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:54:23 by mannette          #+#    #+#             */
/*   Updated: 2020/02/28 20:01:03 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_com	*ft_delete(t_com **command)
{
	t_com	*lst;
	int		j;

	j = 2;
	while (j > 0)
	{
		lst = *command;
		*command = (*command)->next;
		free(lst);
		j--;
	}
	return (*command);
}

t_com	*ft_del(t_com **command)
{
	t_com	*lst;
	t_com	*lst1;
	char	*s;

	s = "rr\n";
	(*command)->str = s;
	lst1 = (*command)->next;
	lst = (*command)->next->next;
	free(lst1);
	return (lst);
}

int		comm(t_com *lst1)
{
	char	*s;
	char	*s1;
	char	*s2;
	char	*s3;

	s = "pa\n";
	s1 = "pb\n";
	s2 = "ra\n";
	s3 = "rra\n";
	if (lst1->next != NULL && lst1->next->next != NULL)
	{
		if (((lst1->next->str == s) && (lst1->next->next->str == s1))
			|| ((lst1->next->str == s1) && (lst1->next->next->str == s)))
			return (1);
		else if (((lst1->next->str == s2) && (lst1->next->next->str == s3))
			|| ((lst1->next->str == s3) && (lst1->next->next->str == s2)))
			return (1);
	}
	return (0);
}

int		comm1(t_com *lst1)
{
	char	*s2;
	char	*s3;

	s2 = "ra\n";
	s3 = "rb\n";
	if (((lst1->str == s2) && (lst1->next->str == s3))
			|| ((lst1->str == s3) && (lst1->next->str == s2)))
		return (1);
	else
		return (0);
}

void	ft_double(t_com **command)
{
	t_com	*com;
	int		used;

	com = *command;
	while (com->next != NULL)
	{
		used = -1;
		if (comm1(com) == 1)
		{
			com->next = ft_del(&com);
			used = 1;
		}
		else if (comm(com) == 1)
		{
			com->next = ft_delete(&com->next);
			used = 1;
		}
		if (used == -1)
			com = com->next;
		else
			com = *command;
	}
}
