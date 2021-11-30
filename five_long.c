#include "push_swap.h"
static t_arr	ft_sorting(t_arr arr);

t_arr			is_min(t_arr arr);

static int		check_swap(t_arr arr, int size);

t_arr	ft_len_five(t_arr arr, int size)
{
	if (check_swap(arr, size) == 0)
	{
		arr = ft_swap_a(arr);
		return (arr);
	}
	arr = is_min(arr);
	arr = ft_sorting(arr);
	arr = is_min(arr);
	if (size == 5)
		arr = ft_sorting(arr);
	arr = ft_len_three(arr, 3);
	arr = ft_push_a(arr);
	arr = ft_push_a(arr);
	return (arr);
}

static int	check_swap(t_arr arr, int size)
{
	int		second;
	int		third;
	int		fourth;
	int		fifth;

	second = arr.array_a[1];
	third = arr.array_a[2];
	fourth = arr.array_a[3];
	if (size == 5)
		fifth = arr.array_a[4];
	else if (arr.array_a[0] > second && \
	third < fourth && arr.array_a[0] < third)
		return (0);
	if (arr.array_a[0] > second && \
	third < fourth && arr.array_a[0] < third && fourth < fifth)
		return (0);
	return (1);
}

static t_arr	ft_sorting(t_arr arr)
{
	int	i;

	i = 0;
	while (i < arr.size_a)
	{
		if (arr.array_a[0] == arr.min)
		{
			arr = ft_push_b(arr);
			return (arr);
		}
		else if (arr.min_pos < (arr.size / 2))
			arr = ft_rotate_a(arr);
		else
			arr = ft_reverse_a(arr);
		i++;
	}
	return (arr);
}

t_arr	is_min(t_arr arr)
{
	int	i;

	i = 0;
	arr.min = arr.array_a[i];
	arr.min_pos = i;
	while (i < arr.size_a)
	{
		if (arr.array_a[i] < arr.min)
		{
			arr.min = arr.array_a[i];
			arr.min_pos = i;
		}
		i++;
	}
	return (arr);
}
