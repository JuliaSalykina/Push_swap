/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:34:06 by mannette          #+#    #+#             */
/*   Updated: 2019/05/01 19:35:19 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **mas)
{
	size_t	i;

	i = 0;
	while (mas && mas[i])
	{
		ft_strdel(&mas[i]);
		i++;
	}
	ft_strdel(mas);
}