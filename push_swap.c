/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:13:12 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/23 18:41:18 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*stk_maker(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	char **arr;

	i = 1;
	stack = NULL;
	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		i=0;
	}
	else
		arr = av;
	if (dupchecker(arr) == 0)
	{
		printf("duplicates");
		return (0);
	}
	while (arr[i] != 0)
	{
		if (digit_checker(arr[i]) != 0)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(arr[i])));
		else
		{
			printf("ERROR");
		
			stack = NULL;
			return (stack);
		}
		i++;
	}
	return (stack);
}

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
	if (stack_a && sort_checker(stack_a) == 0)
	{
		if (ac >= 2 && ac <= 11)
			small_sorter(&stack_a, &stack_b, &op);
		if (ac >= 10 && ac <= 600)
			big_sorter(&stack_a, &stack_b, &op);
	}
	// print_stack(&stack_a);
	print_op(&op);
}
