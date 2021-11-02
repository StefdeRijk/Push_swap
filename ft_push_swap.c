#include "push_swap.h"
#include <stdio.h>
static void	ft_algorithm(int *array_a, int *array_b);

int	main(int argc, char **argv)
{
	int	*array_a;
	int	*array_b;
	int	arguments;
	int	i;

	i = 0;
	arguments = argc - 1;
	if (argc <= 1 || !argv)
		return (0);
	array_a = malloc((arguments - 1) * sizeof(int));
	array_b = malloc((arguments - 1) * sizeof(int));
	if (!array_a || !array_b)
		return (0);
	while (i < arguments)
	{
		array_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_algorithm(array_a, array_b);
	write(1, "\n", 1);
	i = 0;
	while (i < arguments)
	{
		printf("%p	%p\n", &array_a[i], &array_b[i]);
		i++;
	}
	free (array_a);
	return (0);
}

static void	ft_algorithm(int *array_a, int *array_b)
{
	char	operation;

	operation = 'a';
	ft_swap(array_a, array_b, operation);
	operation = 'b';
	ft_swap(array_a, array_b, operation);
	operation = 's';
	ft_swap(array_a, array_b, operation);
	operation = 'a';
	ft_push(array_a, array_b, operation);
	operation = 'b';
	ft_push(array_a, array_b, operation);
}
