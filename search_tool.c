/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:34:34 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/01 13:28:13 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int better_index(t_stack **stack, int content)
{
	int ind;
	t_stack *tmp;

	ind = 1;
	tmp = (*stack);
	while(tmp)
	{
		if (tmp->content<content)
			ind++;
		tmp = tmp->next;
	}
	return(ind);
}

int	*check_small(t_stack **stack_a, int sz)
{
	t_stack	*tmp;
	int		*nbs;
	int		i;

	i = 0;
	nbs = malloc(sizeof (int) * sz);
	tmp = (*stack_a);
	while (tmp)
	{
		if (better_index(stack_a, tmp->content) <= sz)
		{
			nbs[i] = tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
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
