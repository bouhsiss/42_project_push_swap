/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:28:33 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/07 01:01:43 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	digit_checker(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-' || nb[0] == '+')
		i++;
	while (nb[i])
	{
		if (!(ft_isdigit(nb[i])))
			return (0);
		i++;
	}
	return (1);
}

int	dupchecker(char **av, int i)
{
	int	j;

	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sort_checker(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	if (!(*stack))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
