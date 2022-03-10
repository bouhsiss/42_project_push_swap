#include"push_swap.h"

void	sort_3(t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	int		i_min;
	int		i_max;

	i_min = ind_min(stack_a);
	i_max = ind_max(stack_a);
	if (i_min == 2 && i_max == 3)
		pre_execute("sa", stack_a, stack_b, op);
	if (i_min == 3 && i_max == 2)
		pre_execute("rra", stack_a, stack_b, op);
	if (i_min == 2 && i_max == 1)
		pre_execute("ra", stack_a, stack_b, op);
	if (i_min == 1 && i_max == 2)
	{
		pre_execute("sa", stack_a, stack_b, op);
		pre_execute("ra", stack_a, stack_b, op);
	}
	if (i_min == 3 && i_max == 1)
	{
		pre_execute("sa", stack_a, stack_b, op);
		pre_execute("rra", stack_a, stack_b, op);
	}
}

void small_sorter(t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	int i_min;

	i_min = ind_min(stack_a);
	while (ft_lstsize((*stack_a)) !=3)
	{
		push_min_a(i_min, stack_a, stack_b, op);
		pre_execute("pb", stack_a, stack_b, op);
	}
	sort_3(stack_a, stack_b, op);
	while((*stack_b) != 0)
	{
		push_max_b(i_min, stack_a, stack_b, op);
		pre_execute("pa", stack_a, stack_b, op);
	}
}