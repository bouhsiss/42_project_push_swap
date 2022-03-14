#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>

typedef	struct t_stack
{
	int 	content;
	struct t_stack *next;
}t_stack;

typedef struct t_op
{
	char *operation;
	struct t_op *next;
}t_op;

t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	print_stack(t_stack **stack);
void	print_op(t_op **op);
void	swap(t_stack **stack);
void	r_stack(t_stack **stack);
void	revr_stack(t_stack **stack);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1,char *s2);
void	pre_execute(char *action, t_stack **a, t_stack **b, t_op **op);
t_op	*ft_opnew(char *content);
void	ft_opadd_back(t_op **lst, t_op *new);
void	small_sorter(t_stack **stack_a, t_stack **stack_b, t_op **op);
int		ind_min(t_stack **stack);
int		ind_max(t_stack **stack);
void	sort_3(t_stack **stack_a, t_stack **stack_b, t_op **op);
void	push(t_stack **stk_src, t_stack **stk_dest);
int		up_or_down(int i_min, t_stack **stack_a);
void	big_sorter(t_stack **stack_a, t_stack **stack_b, t_op **op);
int get_val(t_stack **stack, int ind);
int get_ind(t_stack **stack, int val);
void make_on_top_a(int ind, t_stack **stack_a, t_stack **stack_b, t_op **op);
void make_on_top_b(int ind, t_stack **stack_a, t_stack **stack_b, t_op **op);

#endif