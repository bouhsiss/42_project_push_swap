/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:28:33 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/26 17:39:16 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

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

int	dupchecker(char **av)
{
	int	i;
	int	j;

	i = 1;
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
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
