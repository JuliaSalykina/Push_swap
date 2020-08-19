/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:21:08 by mannette          #+#    #+#             */
/*   Updated: 2020/03/03 22:37:31 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end(t_all *all, int j)
{
	if (j == 0)
		write(1, "Error\n", 6);
	else if (j == 1)
		print_com(all);
	else if (j == 2)
		ft_print_color(all);
	delete_lst(all);
}

int		main(int argc, char **argv)
{
	t_all	all;
	int		res;
	int		res1;
	int		j;

	all.first = NULL;
	all.second = NULL;
	if (argc > 1)
	{
		j = 1;
		if (ft_strcmp(argv[1], "-c") == 0)
			j = 2;
		res = ft_valid(argv, argc, j, &all);
		if (res == 0)
			ft_end(&all, res);
		else
		{
			res1 = ft_mas_sort(res, &all);
			ft_end(&all, j);
		}
	}
	else
		write(1, "usage: ./push_swap numbers\n", 27);
	return (0);
}
