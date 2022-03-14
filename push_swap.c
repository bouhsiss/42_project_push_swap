#include"push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	checker(char *nb)
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

t_stack	*stk_maker(char **av)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	if (dupchecker(av) == 0)
	{
		printf("duplicates");
		return (0);
	}
	while (av[i])
	{
		if (checker(av[i]) != 0)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i])));
		else
		{
			printf("wrong number");
			stack = NULL;
			return (stack);
		}
		i++;
	}
	return (stack);
}

int	sort_checker(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_op	*op;

	op = NULL;
	stack_b = NULL;
	if (ac == 1)
		printf("needs more argument");
	stack_a = stk_maker(av);
	if (stack_a && sort_checker(stack_a) == 0)
	{
		if (ac >= 3 && ac <= 11)
			small_sorter(&stack_a, &stack_b, &op);
		// if (ac >= 10 && ac <= 100)
		// 	big_sorter(&stack_a, &stack_b, &op);
	}
	print_stack(&stack_a);
	// printf("---------------\n");
	// print_op(&op);
}
