/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mas.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:17:29 by mannette          #+#    #+#             */
/*   Updated: 2020/03/03 22:34:35 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mas(int *mas)
{
	if (!mas)
		return ;
	free(mas);
	mas = NULL;
}

void	find_sort(t_push **first, int *mas, int k)
{
	t_push	*lst;
	int		i;

	lst = *first;
	while (lst)
	{
		i = 0;
		while (i < k)
		{
			if ((lst->num) == mas[i])
			{
				lst->sort_ind = i;
				break ;
			}
			else
				i++;
		}
		lst = lst->next;
	}
	free_mas(mas);
}

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		ft_mas_sort(int k, t_all *all)
{
	t_push	*lst;
	int		j;
	int		num;
	int		*mas;

	j = 0;
	lst = all->first;
	if (!(mas = (int*)malloc(sizeof(int) * (k))))
		return (0);
	while (lst)
	{
		num = lst->num;
		mas[j] = num;
		lst = lst->next;
		j++;
	}
	all->next_elem = 0;
	j = 0;
	sort_int_tab(mas, k);
	find_sort(&all->first, mas, k);
	if (check(&all->first, &all->second, j) == 0)
		ft_sorting(all, k);
	return (1);
}
