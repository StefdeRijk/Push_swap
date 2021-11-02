#include "push_swap.h"
static void	ft_swap_a(int *array_a);

static void	ft_swap_b(int *array_b);

static void	ft_swap_both(int *array_a, int *array_b);

void	ft_swap(int *array_a, int *array_b, char operation)
{
	if (operation == 'a')
		ft_swap_a(array_a);
	if (operation == 'b')
		ft_swap_b(array_b);
	if (operation == 's')
		ft_swap_both(array_a, array_b);
}

static void	ft_swap_a(int *array_a)
{
	int	temp;

	if (!array_a || !array_a[1])
		return ;
	temp = array_a[0];
	array_a[0] = array_a[1];
	array_a[1] = temp;
	write(1, "sa\n", 3);
}

static void	ft_swap_b(int *array_b)
{
	int	temp;

	if (!array_b || !array_b[1])
		return ;
	temp = array_b[0];
	array_b[0] = array_b[1];
	array_b[1] = temp;
	write(1, "sb\n", 3);
}

static void	ft_swap_both(int *array_a, int *array_b)
{
	int	temp;

	if (!array_a || !array_b || !array_a[1] || !array_b[1])
		return ;
	temp = array_a[0];
	array_a[0] = array_a[1];
	array_a[1] = temp;
	temp = array_b[0];
	array_b[0] = array_b[1];
	array_b[1] = temp;
	write(1, "ss\n", 3);
}
