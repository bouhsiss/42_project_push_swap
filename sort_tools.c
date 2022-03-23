/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:18:56 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/19 16:20:03 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	up_or_down(int val, t_stack **stack_a)
{
	int	size;

	size = ft_lstsize((*stack_a));
	if (val <= (size / 2))
		return (1);
	else
		return (-1);
}

int	get_val(t_stack **stack, int ind)
{
	t_stack	*tmp;
	int		content;

	tmp = (*stack);
	while (ind)
	{
		content = tmp->content;
		tmp = tmp->next;
		ind--;
	}
	return (content);
}

int	get_ind(t_stack **stack, int val)
{
	t_stack	*tmp;
	int		ind;

	tmp = (*stack);
	ind = 1;
	while (tmp)
	{
		if (tmp->content == val)
			return (ind);
		tmp = tmp->next;
		ind++;
	}
	return (-1);
}

void	make_on_top_a(int ind, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	int	val;

	val = get_val(stack_a, ind);
	if (up_or_down(ind, stack_a) == 1)
	{
		while (get_ind(stack_a, val) != 1)
			pre_execute("ra", stack_a, stack_b, op);
	}
	if (up_or_down(ind, stack_a) == -1)
	{
		while (get_ind(stack_a, val) != 1)
			pre_execute("rra", stack_a, stack_b, op);
	}
}

void	make_on_top_b(int ind, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	int	val;

	val = get_val(stack_b, ind);
	if (up_or_down(ind, stack_b) == 1)
	{
		while (get_ind(stack_b, val) != 1)
			pre_execute("rb", stack_a, stack_b, op);
	}
	if (up_or_down(ind, stack_b) == -1)
	{
		while (get_ind(stack_b, val) != 1)
			pre_execute("rrb", stack_a, stack_b, op);
	}
}
