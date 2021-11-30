#include "push_swap.h"
void	ft_error(t_arr arr)
{
	write(1, "Error\n", 6);
	free(arr.array_a);
	free(arr.array_b);
	free(arr.sorted_array);
	free(arr.sorted_pos);
	exit (0);
}
