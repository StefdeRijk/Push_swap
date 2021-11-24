#include "push_swap.h"
static t_arr	ft_sort_three(t_arr arr, int first, int second, int third);

static t_arr	ft_sort_two(t_arr arr);

t_arr	ft_len_three(t_arr arr, int size)
{
	t_list	*copy;
	int		first;
	int		second;
	int		third;

	if (size == 1)
		return (arr);
	if (size == 2)
		return (ft_sort_two(arr));
	copy = arr.array_a;
	first = *((int *)copy->content);
	copy = copy->next;
	second = *((int *)copy->content);
	copy = copy->next;
	third = *((int *)copy->content);
	arr = ft_sort_three(arr, first, second, third);
	return (arr);
}

static t_arr	ft_sort_two(t_arr arr)
{
	t_list	*next;

	next = arr.array_a->next;
	if (*((int *)arr.array_a->content) > *((int *)next->content))
		arr = ft_swap(arr, 'a');
	return (arr);
}

static t_arr	ft_sort_three(t_arr arr, int first, int second, int third)
{
	if (third > second && second > first)
		return (arr);
	else if (third > first && first > second)
		arr = ft_swap(arr, 'a');
	else if (first > third && third > second)
		arr = ft_rotate(arr, 'a');
	else if (second > first && first > third)
		arr = ft_reverse(arr, 'a');
	else if (second > third && third > first)
	{
		arr = ft_swap(arr, 'a');
		arr = ft_rotate(arr, 'a');
	}
	else
	{
		arr = ft_swap(arr, 'a');
		arr = ft_reverse(arr, 'a');
	}
	return (arr);
}
