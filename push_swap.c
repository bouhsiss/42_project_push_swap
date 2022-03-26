/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:13:12 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/26 15:27:30 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_op	*op;

	op = NULL;
	stack_b = NULL;
	if (ac == 1)
		printf("needs more argument");
	stack_a = stk_maker(ac, av);
	if (stack_a && sort_checker(&stack_a) == 0)
	{
		if (ac >= 2 && ac <= 11)
			small_sorter(&stack_a, &stack_b, &op);
		if (ac >= 10 && ac <= 600)
			big_sorter(&stack_a, &stack_b, &op);
	}
	print_op(&op);
}
