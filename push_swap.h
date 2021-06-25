#ifndef PUSH_SWAP_H
#include "./libft/libft.h"
#include "./gnl_working/get_next_line.h"
#include <stdio.h>
//#include "Memd/mem.h"
#define A 0
#define B 1
#define OPS "sa sb ss pa pb ra rb rr rra rrb rrr"

typedef struct	s_stack
{
	int elem;
	int group;
	struct s_stack *n;
}				t_stack;
typedef struct	s_main
{	
	t_stack		*stacka;
	t_stack		*stackb;
	t_stack		*chunks;
	t_stack		*chun2;
	int			cutsize;
	char		*op;
}				t_main;
int	twodlen(char **str);
int is_var(char **argv);
int exit_push_swap(char *message);
int number_is_valid(char *str);
int is_present(int *nb, int len, int to_insert);
int fill_stacka(int **stacka, int *nb, int len);
int check_nonvar_format(int **stacka, int *argc, char **argv, int mode);
int check_var_format(int **stacka, int *argc, char **argv);
int check_format(int **stacka, int *argc, char **argv);

void fill_stacka2(t_stack **stack, int **stacka, int len);
int push(t_stack **stack, int elem);
int push2(t_stack **stack, int elem, int group);
void print_stack(t_stack *stack);
int stack_len(t_stack *stack);
int s(t_stack **stack);
int p(t_stack **src, t_stack **dst);
int r(t_stack **stack);
int rev_r(t_stack **stack);
int rr(t_stack **a, t_stack **b);
int rrr(t_stack **a, t_stack **b);
int listen_op(t_main *main);
void init_main(t_main *main);
int is_op(char *op);
int exec_op(t_main *main);

#endif
