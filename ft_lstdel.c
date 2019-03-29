/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:19:49 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 19:48:16 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Функция удаляет элемент списка, который передан по ссылке и все элементы на
** которые он ссылается
*/

void	ft_lstdel(t_lbft_list **alst, void (*del)(void *, size_t))
{
	t_lbft_list *tmp;
	t_lbft_list *next;

	tmp = *alst;
	if (del != NULL)
	{
		while (tmp != NULL)
		{
			next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = next;
		}
		*alst = NULL;
	}
}
