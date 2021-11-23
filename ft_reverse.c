#include "push_swap.h"
static t_arr	ft_reverse_a(t_arr arr, int print);

static t_arr	ft_reverse_b(t_arr arr, int print);

static t_arr	ft_reverse_both(t_arr arr);

static t_list	*ft_rotate_list(t_list *array);

t_arr	ft_reverse(t_arr arr, char operation)
{
	if (operation == 'a')
		arr = ft_reverse_a(arr, 1);
	if (operation == 'b')
		arr = ft_reverse_b(arr, 1);
	if (operation == 's')
		arr = ft_reverse_both(arr);
	return (arr);
}

static t_arr	ft_reverse_a(t_arr arr, int print)
{
	int	len;

	if (!arr.array_a)
		return (arr);
	len = ft_lstsize(arr.array_a) - 1;
	while (len > 0)
	{
		arr.array_a = ft_rotate_list(arr.array_a);
		len--;
	}
	if (print == 1)
		write(1, "rra\n", 4);
	return (arr);
}

static t_arr	ft_reverse_b(t_arr arr, int print)
{
	int	len;

	if (!arr.array_b)
		return (arr);
	len = ft_lstsize(arr.array_b) - 1;
	while (len > 0)
	{
		arr.array_b = ft_rotate_list(arr.array_b);
		len--;
	}
	if (print == 1)
		write(1, "rrb\n", 4);
	return (arr);
}

static t_arr	ft_reverse_both(t_arr arr)
{
	if (!arr.array_a && !arr.array_b)
		return (arr);
	if (arr.array_a)
		arr = ft_reverse_a(arr, 0);
	if (arr.array_b)
		arr = ft_reverse_b(arr, 0);
	write(1, "rrr\n", 4);
	return (arr);
}

static t_list	*ft_rotate_list(t_list *array)
{
	t_list	*copy;
	t_list	*new;
	int		*num;
	int		len;

	if (!array && !array->next)
		return (array);
	len = ft_lstsize(array);
	if (len == 1)
		return (array);
	copy = (t_list *)malloc(sizeof(t_list *));
	num = malloc(sizeof(int));
	if (!num || !copy)
		return (array);
	copy = array;
	array = array->next;
	*num = *((int *)copy->content);
	new = ft_lstnew(num);
	ft_lstadd_back(&array, new);
	ft_lstdelone(copy, &ft_delete);
	return (array);
}
