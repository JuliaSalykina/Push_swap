/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:25:18 by mannette          #+#    #+#             */
/*   Updated: 2020/03/02 16:01:53 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		symb(char *n)
{
	int i;

	i = 0;
	while (n[i])
	{
		if ((n[i] == '-' || n[i] == '+') && (n[i + 1] >= 48 && n[i + 1] <= 57))
			i++;
		else if (n[i] >= 48 && n[i] <= 57)
			i++;
		else if ((n[i] >= 8 && n[i] <= 13) || n[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_integer(char *n, int num, int i, int j)
{
	char	*res;

	res = ft_itoa(num);
	while ((n[i] >= 8 && n[i] <= 13) || n[i] == ' ')
		i++;
	if (n[i] == '+' && n[i + 1] == '0')
		return (-1);
	if (n[i] == '+')
		i++;
	while (!((n[i] >= 8 && n[i] <= 13) || n[i] == ' ') && n[i] == res[j]
		&& res[j] != '\0')
	{
		i++;
		j++;
	}
	if ((n[i] == ' ' || n[i] == '\0') && res[j] == '\0')
	{
		ft_strdel(&res);
		return (0);
	}
	i = n[i] - res[j];
	ft_strdel(&res);
	return (i);
}

int		ft_valid1(char *n, t_all *all)
{
	t_push	*lst;
	int		i;
	int		res;

	i = 0;
	if (symb(n) == 0)
		return (0);
	while (*n)
	{
		while (((*n >= 8 && *n <= 13) || *n == ' '))
			n++;
		if (*n != '\0')
		{
			i++;
			res = ft_atoi(n);
			if (ft_integer(n, res, 0, 0) != 0)
				return (0);
			if ((lst = create_lst(all, res)) == NULL)
				return (0);
		}
		while ((*n == '-' || *n == '+') || (*n >= 48 && *n <= 57))
			n++;
	}
	return (i);
}

int		ft_valid(char **n, int str, int j, t_all *all)
{
	int			i;
	int			res;

	i = 0;
	while (j < str)
	{
		res = ft_valid1(n[j], all);
		if (res == 0)
			return (0);
		i += res;
		j++;
	}
	return (i);
}
