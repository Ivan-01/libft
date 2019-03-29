/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funintarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:18:25 by ititkov           #+#    #+#             */
/*   Updated: 2018/12/20 20:23:06 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_funintarr(int *array, int lent, int num, double (*f)(double, double))
{
	int		i;

	i = 0;
	if (f != NULL)
	{
		while (i <= lent)
		{
			array[i] = f(array[i], num);
			i++;
		}
	}
}
