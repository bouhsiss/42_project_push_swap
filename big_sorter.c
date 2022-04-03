/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:08:28 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/03 23:02:13 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	chunk_sz(int size)
{
	if (size <= 30)
		return (size / 2);
	else if (size > 30 && size <= 80)
		return (size / 3);
	else if (size > 80 && size <= 150)
		return (20);
	else if (size > 150 && size <= 250)
		return (25);
	else if (size > 250 && size <= 300)
		return (40);
	else if (size > 300 && size <= 400)
		return (50);
	return (60);
}

void	push_chunks(int *nbs, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	t_stack	*tmp;
	int		sz;
	int		i;

	i = 0;
	tmp = (*stack_a);
	sz = chunk_sz(ft_lstsize(tmp));
	while (sz)
	{
		make_on_top_a(get_ind(stack_a, nbs[i]), stack_a, stack_b, op);
		tmp = tmp->next;
		pre_execute("pb", stack_a, stack_b, op);
		i++;
		sz--;
	}
}

void	big_sorter(t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	int	*nbs;
	int	sz;

	while (ft_lstsize((*stack_a)) >= 10)
	{	
		sz = chunk_sz(ft_lstsize(*stack_a));
		nbs = check_small(stack_a, sz);
		push_chunks(nbs, stack_a, stack_b, op);
		free(nbs);
	}
	small_sorter(stack_a, stack_b, op);
	while ((*stack_b))
	{
		make_on_top_b(ind_max(stack_b), stack_a, stack_b, op);
		pre_execute("pa", stack_a, stack_b, op);
	}
}
