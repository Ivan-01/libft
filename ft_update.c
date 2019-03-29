/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:26:51 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 15:32:07 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_update(char *str, char *update)
{
	char	*tmp;

	tmp = update;
	if (str != NULL)
		free(str);
	str = update;
	return (str);
}
