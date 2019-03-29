/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:51:00 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 19:53:02 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Comment
*/

t_lbft_list			*ft_lstmap(t_lbft_list *lst, t_lbft_list *(*f)\
		(t_lbft_list *elem))
{
	t_lbft_list		*newlist;

	if (lst != NULL && f != NULL)
	{
		newlist = f(lst);
		if (newlist != NULL && lst->next != NULL)
			newlist->next = ft_lstmap(lst->next, f);
		return (newlist);
	}
	return (NULL);
}
