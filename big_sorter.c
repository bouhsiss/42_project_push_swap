/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:08:28 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/28 18:10:06 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_chunks(int *nbs, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (nbs_search(nbs[i], stack_a))
		{
			make_on_top_a(get_ind(stack_a, nbs[i]), stack_a, stack_b, op);
			tmp = tmp->next;
			pre_execute("pb", stack_a, stack_b, op);
			i++;
			continue ;
		}
			tmp = tmp->next;
	}
}

int	chunk_sz(int sz)
{
	if (sz < 100)
		return (15);
	if (sz >= 100 && sz < 200)
		return (20);
	if (sz >= 200 && sz < 300)
		return (30);
	if (sz >= 300 && sz < 400)
		return (35);
	if (sz >= 400 && sz < 500)
		return (40);
	return (45);
}

void	big_sorter(t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	int	*nbs;
	int	range;
	int	sz;
	int	size;

	range = 0;
	size = 0;
	size = ft_lstsize((*stack_a));
	while (ft_lstsize((*stack_a)))
	{	
		sz = chunk_sz(ft_lstsize(*stack_a));
		nbs = check_small(range, stack_a, sz);
		push_chunks(nbs, stack_a, stack_b, op);
		range = range + sz;
	}
	while ((*stack_b))
	{
		make_on_top_b(ind_max(stack_b), stack_a, stack_b, op);
		pre_execute("pa", stack_a, stack_b, op);
	}
}
