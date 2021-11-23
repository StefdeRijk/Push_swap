#include "push_swap.h"
t_arr	ft_len_five(t_arr arr)
{
	arr = ft_push(arr, 'b');
	arr = ft_push(arr, 'b');
	arr.next_b = arr.array_b->next;
	arr = ft_len_three(arr);
	if (*((int *)arr.array_b->content) > *((int *)arr.array_a->content))
	{
		arr = ft_push(arr, 'a');
		arr = ft_rotate(arr, 'a');
		arr = ft_push(arr, 'a');
	}
	else
	{
		arr = ft_push(arr, 'a');
		arr = ft_push(arr, 'a');
		arr = ft_rotate(arr, 'a');
	}
	return (arr);
}
