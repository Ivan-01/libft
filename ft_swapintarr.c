/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapintarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:40:07 by ititkov           #+#    #+#             */
/*   Updated: 2018/12/19 17:17:07 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapintarr(int *array, int num1, int num2)
{
	int		temp;

	if (num1 < 0 || num2 < 0)
		return ;
	temp = array[num1];
	array[num1] = array[num2];
	array[num2] = temp;
}
