/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:34:34 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/28 18:02:49 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	how_many_nbs(t_stack **stack, int min_range, int sz)
{
	int		i;
	t_stack	*tmp;
	int		max_range;

	i = 0;
	max_range = min_range + sz;
	tmp = (*stack);
	while (tmp)
	{
		if (tmp->content >= min_range && tmp->content < max_range)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	*check_small(int min_range, t_stack **stack_a, int sz)
{
	t_stack	*tmp;
	int		*nbs;
	int		i;
	int		max_range;
	int		how_many;

	i = 0;
	how_many = how_many_nbs(stack_a, min_range, sz);
	max_range = min_range + sz;
	nbs = malloc(sizeof (int) * (how_many + 1));
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->content >= min_range && tmp->content < max_range)
		{
			nbs[i] = tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
	nbs[i] = '\0';
	return (nbs);
}

int	nbs_search(int nbs, t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		if (nbs == tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
