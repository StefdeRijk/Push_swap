#include "push_swap.h"
#include <stdio.h>
static t_arr	ft_sorting(t_arr arr);

t_arr			is_min(t_arr arr);

static int		check_swap(t_arr arr, int size);

static int		check_return(t_arr arr, int second, int third, int fourth);

t_arr	ft_len_five(t_arr arr, int size)
{
	if (is_sorted(arr) == 0)
	{
		if (check_swap(arr, size) == 0)
			return (ft_swap(arr, 'a'));
		arr.size = ft_lstsize(arr.array_a);
		arr = is_min(arr);
		arr = ft_sorting(arr);
		arr.size = ft_lstsize(arr.array_a);
		arr = is_min(arr);
		if (size == 5)
			arr = ft_sorting(arr);
		arr = ft_len_three(arr, 3);
		arr = ft_push(arr, 'a');
		arr = ft_push(arr, 'a');
	}
	return (arr);
}

static int	check_swap(t_arr arr, int size)
{
	t_list	*copy;
	int		second;
	int		third;
	int		fourth;
	int		fifth;

	copy = arr.array_a;
	copy = copy->next;
	second = *((int *)copy->content);
	copy = copy->next;
	third = *((int *)copy->content);
	copy = copy->next;
	fourth = *((int *)copy->content);
	copy = copy->next;
	if (size == 5)
		fifth = *((int *)copy->content);
	else
		return (check_return(arr, second, third, fourth));
	if (*((int *)arr.array_a->content) > second && \
	third < fourth && *((int *)arr.array_a->content) < third && fourth < fifth)
		return (0);
	return (1);
}

static int	check_return(t_arr arr, int second, int third, int fourth)
{
	if (*((int *)arr.array_a->content) > second && \
	third < fourth && *((int *)arr.array_a->content) < third)
		return (0);
	return (1);
}

static t_arr	ft_sorting(t_arr arr)
{
	while (ft_lstsize(arr.array_a) == arr.size)
	{
		if (ft_lstsize(arr.min) == ft_lstsize(arr.array_a))
			arr = ft_push(arr, 'b');
		else if (ft_lstsize(arr.min) > (ft_lstsize(arr.array_a) / 2))
			arr = ft_rotate(arr, 'a');
		else
			arr = ft_reverse(arr, 'a');
		arr = ft_sorting(arr);
	}
	return (arr);
}

t_arr	is_min(t_arr arr)
{
	t_list	*current;

	current = arr.array_a;
	arr.min = arr.array_a;
	while (current->next)
	{
		if (*((int *)current->content) < *((int *)arr.min->content))
			arr.min = current;
		current = current->next;
	}
	if (*((int *)current->content) < *((int *)arr.min->content))
		arr.min = current;
	return (arr);
}
