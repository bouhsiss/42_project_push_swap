#include"push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while ((tmp))
	{
		printf("---- %d\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_op(t_op **op)
{
	t_op	*tmp;

	tmp = *op;
	while ((tmp))
	{
		printf("%s\n", tmp->operation);
		tmp = tmp->next;
	}
}

int	ind_min(t_stack **stack)
{
	int		min;
	int		i;
	int		ind;
	t_stack	*tmp;

	i = 1;
	ind = i;
	tmp = *stack;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			ind = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ind);
}

int	ind_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;
	int		ind;
	int		i;

	i = 1;
	ind = i;
	tmp = *stack;
	max = tmp->content;
	while (tmp)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
			ind = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ind);
}
