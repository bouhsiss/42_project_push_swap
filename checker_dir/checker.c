/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:45:44 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/07 01:01:50 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	checker_exec(char **op, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (op[i])
	{
		execute_op(op[i], stack_a, stack_b);
		i++;
	}
	if (sort_checker(stack_a) && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	check_errors(char *op)
{
	if (!(ft_strcmp("sa", op)) || !(ft_strcmp("sb", op)))
		return (1);
	else if (!(ft_strcmp("ss", op)) || !(ft_strcmp("ra", op)))
		return (1);
	else if (!(ft_strcmp("rb", op)) || !(ft_strcmp("rr", op)))
		return (1);
	else if (!(ft_strcmp("rra", op)) || !(ft_strcmp("rrb", op)))
		return (1);
	else if (!(ft_strcmp("rrr", op)) || !(ft_strcmp("pa", op)))
		return (1);
	else if (!(ft_strcmp("pb", op)))
		return (1);
	else
		return (-1);
}

int	main(int ac, char **av)
{
	char	*op[10000];
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (stk_maker(ac, av) && ac > 1)
	{
		stack_a = stk_maker(ac, av);
		op[i] = get_next_line(0);
		while (op[i] != NULL )
		{
			op[i][strlen(op[i]) - 1] = '\0';
			if (check_errors(op[i]) == -1)
			{
				ft_putstr_fd("Error", 2);
				exit(0);
			}
			i++;
			op[i] = get_next_line(0);
		}
		checker_exec(op, &stack_a, &stack_b);
	}
}
