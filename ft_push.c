#include "push_swap.h"
static void	ft_push_a(int *array_a, int *array_b);

static void	ft_push_b(int *array_a, int *array_b);

void	ft_push(int *array_a, int *array_b, char operation)
{
	if (operation == 'a')
		ft_push_a(array_a, array_b);
	if (operation == 'b')
		ft_push_b(array_a, array_b);
}

static void	ft_push_a(int *array_a, int *array_b)
{
	if (!array_b || !*array_b)
		return ;
	array_a[0] = array_b[0];
	write(1, "pa\n", 3);
}

static void	ft_push_b(int *array_a, int *array_b)
{
	if (!array_a || !*array_b)
		return ;
	array_b[0] = array_a[0];
	write(1, "pa\n", 3);
}
