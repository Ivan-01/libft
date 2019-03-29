/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:56:02 by ititkov           #+#    #+#             */
/*   Updated: 2018/12/20 16:09:09 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putintarr(int *array, int size)
{
	int		i;

	i = 0;
	if (size <= 0)
		return (2);
	while (i != size)
	{
		ft_putnbr(array[i]);
		i++;
	}
	return (0);
}
