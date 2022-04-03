/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:47:59 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/03 00:30:14 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*constructor(char **arr, int i)
{
	t_stack			*stack;

	stack = NULL;
	while (arr[i] != 0)
	{
		if (digit_checker(arr[i]) != 0)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(arr[i])));
		else
		{
			ft_putstr_fd("Error\n", 2);
			stack = NULL;
			return (0);
		}
		i++;
	}
	return (stack);
}

t_stack	*stk_maker(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	char	**arr;

	i = 1;
	stack = NULL;
	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		i = 0;
	}
	else
		arr = av;
	if (dupchecker(arr) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack = constructor(arr, i);
	return (stack);
}
