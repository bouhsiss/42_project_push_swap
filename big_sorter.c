#include"push_swap.h"

int chunk_size(t_stack **stack, int mid)
{
	int i;
	t_stack *tmp;

	i = 0;
	tmp = (*stack);
	while(tmp)
	{
		if (tmp->content <= mid)
			i++;
		tmp = tmp->next;
	}
	return(i);
}

int *check_small(int mid, t_stack **stack_a)
{
	t_stack *tmp;
	int *nbs;
	int sz;
	int i;

	i=0;
	sz = chunk_size(stack_a, mid);
	nbs = malloc(sz*sizeof(int));
	tmp = (*stack_a);
	while(tmp)
	{
		if (tmp->content <= mid)
		{
			nbs[i] = tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
	nbs[i] = '\0';
	return(nbs);
}

void push_chunks(int nbs, t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	t_stack *tmp;

	tmp = (*stack_a);
	while(tmp)
	{
		if(nbs == tmp->content)
		{
			make_on_top_a(get_ind(stack_a, nbs), stack_a, stack_b, op);
			pre_execute("pb", stack_a, stack_b, op);
		}
		tmp = tmp->next;
	}
}

void	big_sorter(t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	int mid;
	int *nbs;
	int sz;
	int i;

	while(ft_lstsize((*stack_a)) > 2)
	{
		i = 0;
		mid = (get_val(stack_a, ind_max(stack_a)) + get_val(stack_a, ind_min(stack_a)))/2;
		nbs = check_small(mid, stack_a);
		sz = chunk_size(stack_a, mid);
		while (i<sz)
		{
			push_chunks(nbs[i], stack_a, stack_b, op);
			i++;
		}
	}
}

//check if numbers are smaller than mid and push them to stk_b
