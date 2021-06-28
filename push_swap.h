#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./gnl_working/get_next_line.h"
# include <stdio.h>
# define A 0
# define B 1
# define OPS "sa sb ss pa pb ra rb rr rra rrb rrr"

typedef struct s_stack
{
	int				elem;
	int				group;
	struct s_stack	*n;
}					t_stack;

typedef struct s_main
{	
	t_stack		*stacka;
	t_stack		*stackb;
	t_stack		*chunks;
	t_stack		*chun2;
	int			cutsize;
	int			count;
	char		*op;
}				t_main;

typedef struct s_solve
{
	int			left;
	int			right;
	int			pivot;
	int			swap;
}				t_solve;

int		set_ret(char **ret, int size, int negative);
void	splitnorme(char ***tab, int i, int **arr);
int		new_star_char(char ***str, size_t size);
int		new_char(char **str, size_t size);
int		str_diff(char	*s1, char *s2);
int		send_op2(t_main *main, char *op);
void	send_op(t_main *main, char *op);
int		*get_numbers(char **argv);
void	swap(int *a, int *b);
void	print_loop(char *message, int n);
void	quicksort(int *stack, int start, int end);
void	init_solve(t_solve *solve, int len);
t_stack	*get_last(t_stack *stack);
int		*stack_to_int(t_stack *stack, int len);
int		is_sorted_rev(t_stack *stack, int len);
int		is_sorted(t_stack *stack);
int		move_chunk(t_main *main);
int		get_max(int *stacka, int to_find);
int		case_two_a(t_main *main);
int		get_loc(t_stack *stack, int to_find);
int		small_r(t_main *main, int small);
int		small_l(t_main *main, int small);
void	move_small(t_main *main, int *stacka, int mid);
int		to_b(t_main *main);
int		get_max2(t_main *main, int mid);
int		case_one_b(t_main *main);
int		case_two_b(t_main *main);
void	case_sorted_b(t_main *main);
void	rev_count_r(t_main *main, int count_r);
void	to_a_part2(t_main *main, int *stacka);
int		to_a_case(t_main *main, int *stacka);
int		to_a(t_main *main, int *stacka);
int		get_lloc(t_stack *stack, int to_find, int len);
int		get_path(t_stack *stack, t_main *main, int to_find);
int		mv_elem_top(t_stack **stack, int to_find);
int		check_cases(t_main *main);
int		get_max3(t_main *main, int mid, int size);
int		move_small2(t_main *main, int *stacka, int mid);
int		split_len(char **split);
int		is_present2(char **curr, int to_find);
void	chunkify2(t_main	*main, t_stack *tmp);
int		chunkify(t_main *main);
int		to_a2_move_to_top(t_main *main, int to_find);
void	to_a2_2(t_main *main);
int		to_a2(t_main *main);
int		init_stack_sort(t_main *main, int *stacka, int len);
void	set_cutsize(t_main *main, int len);
int		case_two(int *stacka, int len);
void	free_stack(t_main *main);
int		main(int argc, char **argv);
int		twodlen(char **str);
int		free_2dtab(char ***to_free, int ret);
int		is_var(char **argv);
int		exit_push_swap(t_main *main, char *message);
int		number_is_valid(char *str);
int		is_present(int *nb, int len, int to_insert);
int		fill_stacka(int **stacka, int *nb, int len);
int		*new_int(int size);
int		check_part3(char **argv, int *nb, int mode, int i);
int		check_part4(char *tmp, char **argv, int i);
int		check_nonvar_format(int **stacka, int *argc, char **argv, int mode);
int		check_var_format(int **stacka, int *argc, char **argv);
int		check_format(int **stacka, int *argc, char **argv);
void	fill_stacka2(t_stack **stack, int **stacka, int len);
int		push(t_stack **stack, int elem);
void	print_stack(t_stack *stack);
int		stack_len(t_stack *stack);
int		s(t_stack **stack);
int		p(t_stack **src, t_stack **dst);
int		r(t_stack **stack);
int		rev_r(t_stack **stack);
int		is_op(char *op);
int		exec_op(t_main *main);

#endif
