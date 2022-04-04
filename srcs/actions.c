/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:39:39 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/03 23:58:49 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	swap(t_stack **stack)
{
	int	i;
	int	j;

	i = (*stack)->content;
	j = (*stack)->next->content;
	(*stack)->content = j;
	(*stack)->next->content = i;
}

void	push(t_stack **stk_src, t_stack **stk_dest)
{
	int		i;
	t_stack	*tmp;

	i = (*stk_src)->content;
	tmp = NULL;
	ft_lstadd_front(stk_dest, ft_lstnew(i));
	tmp = (*stk_src);
	(*stk_src) = (*stk_src)->next;
	free(tmp);
}

void	r_stack(t_stack **stack)
{
	int		first;
	t_stack	*tmp;

	tmp = (*stack);
	first = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = first;
}

void	revr_stack(t_stack **stack)
{
	int		first;
	int		second;
	t_stack	*tmp;

	tmp = *stack;
	first = tmp->content;
	while (tmp->next)
	{
		second = tmp->next->content;
		tmp->next->content = first;
		first = second;
		tmp = tmp->next;
	}
	(*stack)->content = first;
}
