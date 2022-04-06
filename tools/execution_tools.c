/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:12:08 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/06 21:07:52 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	exec_extended(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp("rrr", action) == 0 && (*stack_b) && (*stack_a))
	{
		revr_stack(stack_a);
		revr_stack(stack_b);
	}
	else if (ft_strcmp("pa", action) == 0 && (*stack_b))
		push(stack_b, stack_a);
	else if (ft_strcmp("pb", action) == 0 && (*stack_a))
		push(stack_a, stack_b);
	else
	{
		ft_putstr_fd("KO", 2);
		exit(0);
	}
}

void	execute_op(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (strcmp("sa", action) == 0 && (*stack_a))
		swap(stack_a);
	else if (ft_strcmp("sb", action) == 0 && (*stack_b))
		swap(stack_b);
	else if (ft_strcmp("ss", action) == 0 && (*stack_b) && (*stack_a))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strcmp("ra", action) == 0 && (*stack_a))
		r_stack(stack_a);
	else if (ft_strcmp("rb", action) == 0 && (*stack_b))
		r_stack(stack_b);
	else if (ft_strcmp("rr", action) == 0 && (*stack_b) && (*stack_a))
	{
		r_stack(stack_a);
		r_stack(stack_b);
	}
	else if (ft_strcmp("rra", action) == 0 && (*stack_a))
		revr_stack(stack_a);
	else if (ft_strcmp("rrb", action) == 0 && (*stack_b))
		revr_stack(stack_b);
	else
		exec_extended(action, stack_a, stack_b);
}

void	pre_execute(char *action, t_stack **a, t_stack **b, t_op **op)
{
	execute_op(action, a, b);
	ft_opadd_back(op, ft_opnew(action));
}
