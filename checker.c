#include"push_swap.h"

t_stack	*stk_maker(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	char **arr;

	i = 1;
	stack = NULL;
	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		i=0;
	}
	else
		arr = av;
	if (dupchecker(arr) == 0)
	{
		printf("duplicates");
		return (0);
	}
	while (arr[i] != 0)
	{
		if (digit_checker(arr[i]) != 0)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(arr[i])));
		else
		{
			printf("ERROR");
		
			stack = NULL;
			return (stack);
		}
		i++;
	}
	return (stack);
}

int main(int ac, char **av)
{
	char *op[10000];
	int i = 0;
	t_stack *stack_a;
	t_stack *stack_b;

	while((op[i] = get_next_line(0)) != NULL)
		i++;
	op[i] = NULL;
}
