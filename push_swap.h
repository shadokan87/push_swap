#ifndef PUSH_SWAP_H
#include "./libft/libft.h"
#include "./gnl_working/get_next_line.h"
#include <stdio.h>
#define A 0
#define B 1
#define LIST_ELEM

typedef struct	s_stack
{
	int elem;
	struct s_stack *n;
}				t_stack;
typedef struct	s_main
{	
	t_stack		*stack[2];
	char		*op;
}				t_main;
#endif
