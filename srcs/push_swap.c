/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:13:12 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/03 23:59:08 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_op	*op;
	int		size;

	op = NULL;
	stack_b = NULL;
	stack_a = stk_maker(ac, av);
	size = ft_lstsize(stack_a);
	if (stack_a && sort_checker(&stack_a) == 0)
	{
		if (size >= 1 && size < 10)
			small_sorter(&stack_a, &stack_b, &op);
		if (size >= 10 && size <= 500)
			big_sorter(&stack_a, &stack_b, &op);
	}
	print_op(&op);
}
