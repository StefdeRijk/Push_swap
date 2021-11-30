#include "push_swap.h"
static t_arr	ft_sort_three(t_arr arr, int first, int second, int third);

static t_arr	ft_sort_two(t_arr arr);

t_arr	ft_len_three(t_arr arr, int size)
{
	int		first;
	int		second;
	int		third;

	if (size == 1)
		return (arr);
	if (size == 2)
		return (ft_sort_two(arr));
	first = arr.array_a[0];
	second = arr.array_a[1];
	third = arr.array_a[2];
	arr = ft_sort_three(arr, first, second, third);
	return (arr);
}

static t_arr	ft_sort_two(t_arr arr)
{
	if (arr.array_a[0] > arr.array_a[1])
		arr = ft_swap_a(arr);
	return (arr);
}

static t_arr	ft_sort_three(t_arr arr, int first, int second, int third)
{
	if (third > second && second > first)
		return (arr);
	else if (third > first && first > second)
		arr = ft_swap_a(arr);
	else if (first > third && third > second)
		arr = ft_rotate_a(arr);
	else if (second > first && first > third)
		arr = ft_reverse_a(arr);
	else if (second > third && third > first)
	{
		arr = ft_swap_a(arr);
		arr = ft_rotate_a(arr);
	}
	else
	{
		arr = ft_swap_a(arr);
		arr = ft_reverse_a(arr);
	}
	return (arr);
}
