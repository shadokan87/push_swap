#include "../push_swap.h"
#include <stdio.h>

int	to_a2(t_main *main)
{
	while (main->cutsize && main->chunks->elem > main->cutsize)
		chunkify(main);
	while (main->chunks->elem)
		to_a2_2(main);
	move_chunk(main);
	if (main->stackb)
		return (to_a2(main));
	return (0);
}
