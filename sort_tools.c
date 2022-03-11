#include"push_swap.h"

int	up_or_down(int i_min, t_stack **stack_a)
{
	int	size;

	size = ft_lstsize((*stack_a));
	if (i_min <= (size / 2))
		return (1);
	else
		return (-1);
}

void	push_min_a(int i_min, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	if (up_or_down(i_min, stack_a) == 1)
	{
		while (ind_min(stack_a) != 1)
			pre_execute("ra", stack_a, stack_b, op);
	}
	if (up_or_down(i_min, stack_a) == -1)
	{
		while (ind_min(stack_a) != 1)
			pre_execute("rra", stack_a, stack_b, op);
	}
}

void	push_max_a(int i_max, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	if (up_or_down(i_max, stack_a) == 1)
	{
		while (ind_max(stack_a) != 1)
			pre_execute("ra", stack_a, stack_b, op);
	}
	if (up_or_down(i_max, stack_a) == -1)
	{
		while (ind_max(stack_a) != 1)
			pre_execute("rra", stack_a, stack_b, op);
	}
}

void	push_min_b(int i_min, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	if (up_or_down(i_min, stack_b) == 1)
	{
		while (ind_min(stack_b) != 1)
			pre_execute("rb", stack_a, stack_b, op);
	}
	if (up_or_down(i_min, stack_b) == -1)
	{
		while (ind_min(stack_b) != 1)
			pre_execute("rrb", stack_a, stack_b, op);
	}
}

void	push_max_b(int i_max, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	if (up_or_down(i_max, stack_b) == 1)
	{
		while (ind_max(stack_b) != 1)
			pre_execute("rb", stack_a, stack_b, op);
	}
	if (up_or_down(i_max, stack_b) == -1)
	{
		while (ind_max(stack_b) != 1)
			pre_execute("rrb", stack_a, stack_b, op);
	}
}
