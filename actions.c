/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:39:39 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/26 17:10:29 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
		printf("duplicates");
		return (0);
	}
	while (arr[i] != 0)
	{
		if (digit_checker(arr[i]) != 0)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(arr[i])));
		else
		{
			ft_putstr_fd("ERROR", 2);
			stack = NULL;
			return (0);
		}
		i++;
	}
	return (stack);
}

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
