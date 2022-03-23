/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lst_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:11:50 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/19 16:11:52 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_op	*ft_opnew(char *content)
{
	t_op	*new;

	new = (t_op *)malloc(sizeof(t_op));
	if (!new)
		return (NULL);
	new->operation = content;
	new->next = NULL;
	return (new);
}

t_op	*ft_oplast(t_op *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_opadd_back(t_op **lst, t_op *new)
{
	t_op	*list;

	list = *lst;
	if (!new)
		return ;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		list = ft_oplast(*lst);
		list->next = new;
	}
}
