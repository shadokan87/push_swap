#include "../push_swap.h"

int		exit_checker(char *message)
{
	if (!message)
		printf("Error\n");
	else
		printf("%s", message);
	return (0);
}

int		main(int argc, char **argv)
{
	t_main main;
	init_main(&main);
	int *stacka;
	int len;

	len = argc - 1;
	if (!check_format(&stacka, &len, argv))
		return (exit_checker("Error\n"));
	fill_stacka2(&main.stack[A], &stacka, len);
	/*
	while ((get_next_line(STDIN_FILENO, &main.op)))
	{	
		if (!exec_op(&main))
		{
			printf("Error\n");
			break ;
		}
		free(main.op);
	}
	*/
}
