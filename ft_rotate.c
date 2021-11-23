#include "push_swap.h"
static t_arr	ft_rotate_a(t_arr arr, int print);

static t_arr	ft_rotate_b(t_arr arr, int print);

static t_arr	ft_rotate_both(t_arr arr);

t_arr	ft_rotate(t_arr arr, char operation)
{
	if (operation == 'a')
		arr = ft_rotate_a(arr, 1);
	if (operation == 'b')
		arr = ft_rotate_b(arr, 1);
	if (operation == 's')
		arr = ft_rotate_both(arr);
	return (arr);
}

static t_arr	ft_rotate_a(t_arr arr, int print)
{
	t_list	*copy;
	t_list	*new;
	int		*num;
	int		len;

	if (!arr.array_a && !arr.array_a->next)
		return (arr);
	len = ft_lstsize(arr.array_a);
	copy = (t_list *)malloc(sizeof(t_list *));
	num = malloc(sizeof(int));
	if (len == 1 || !copy || ! num)
		return (arr);
	copy = arr.array_a;
	arr.array_a = arr.array_a->next;
	*num = *((int *)copy->content);
	new = ft_lstnew(num);
	ft_lstadd_back(&arr.array_a, new);
	ft_lstdelone(copy, &ft_delete);
	if (print == 1)
		write(1, "ra\n", 3);
	return (arr);
}

static t_arr	ft_rotate_b(t_arr arr, int print)
{
	t_list	*copy;
	t_list	*new;
	int		*num;
	int		len;

	if (!arr.array_b && !arr.array_b->next)
		return (arr);
	len = ft_lstsize(arr.array_b);
	copy = (t_list *)malloc(sizeof(t_list *));
	num = malloc(sizeof(int));
	if (len == 1 || !copy || !num)
		return (arr);
	copy = arr.array_b;
	arr.array_b = arr.array_b->next;
	*num = *((int *)copy->content);
	new = ft_lstnew(num);
	ft_lstadd_back(&arr.array_b, new);
	ft_lstdelone(copy, &ft_delete);
	if (print == 1)
		write(1, "rb\n", 3);
	return (arr);
}

static t_arr	ft_rotate_both(t_arr arr)
{
	if (!arr.array_a && !arr.array_b)
		return (arr);
	if (arr.array_a)
		ft_rotate_a(arr, 0);
	if (arr.array_b)
		ft_rotate_b(arr, 0);
	write(1, "rr\n", 3);
	return (arr);
}
