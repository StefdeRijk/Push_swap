#include "push_swap.h"
static t_arr	ft_algorithm(t_arr arr);

static t_arr	ft_init_array(t_arr arr, char *argv, int i);

int	main(int argc, char **argv)
{
	t_arr	arr;
	int		arguments;

	if (argc <= 2 || !argv)
		return (0);
	arguments = argc - 1;
	arr.size = arguments;
	arr.sorted_array = ft_calloc((arr.size + 1) * sizeof(int), 1);
	arr.array_a = ft_calloc((arr.size + 1) * sizeof(int), 1);
	arr.array_b = ft_calloc((arr.size + 1) * sizeof(int), 1);
	arr.sorted_pos = ft_calloc((arr.size + 1) * sizeof(int), 1);
	if (!arr.sorted_array || !arr.array_a || !arr.array_b || !arr.sorted_pos)
		ft_error(arr);
	while (arguments > 0)
	{
		ft_check_arguments(argv[arguments], arr);
		arr = ft_init_array(arr, argv[arguments], arguments - 1);
		arguments--;
	}
	ft_check_doubles(arr.array_a, arr.size, arr);
	arr = ft_algorithm(arr);
	return (0);
}

static t_arr	ft_init_array(t_arr arr, char *argv, int i)
{
	int		num;

	num = ft_atoi(argv);
	arr.array_a[i] = num;
	arr.sorted_array[i] = num;
	return (arr);
}

static t_arr	ft_algorithm(t_arr arr)
{
	arr.size_a = arr.size;
	arr.size_b = 0;
	if (is_sorted(arr) == 0)
	{
		if (arr.size <= 3)
			return (ft_len_three(arr, arr.size));
		if (arr.size <= 5)
			return (ft_len_five(arr, arr.size));
		else
			return (ft_radix(arr));
	}
	return (arr);
}
