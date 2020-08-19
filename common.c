/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:23:21 by mannette          #+#    #+#             */
/*   Updated: 2020/02/26 19:59:47 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_all *all)
{
	ft_sa(&all->first, &all->command);
	ft_sb(&all->second, &all->command);
}

void	ft_rr(t_all *all)
{
	ft_ra(&all->first, &all->command);
	ft_rb(&all->second, &all->command);
}

void	ft_rrr(t_all *all)
{
	ft_rra(&all->first, &all->command);
	ft_rrb(&all->second, &all->command);
}
