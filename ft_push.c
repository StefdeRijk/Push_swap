#include "push_swap.h"
static t_arr	ft_push_a(t_arr arr);

static t_arr	ft_push_b(t_arr arr);

t_arr	ft_push(t_arr arr, char operation)
{
	if (operation == 'a')
		arr = ft_push_a(arr);
	if (operation == 'b')
		arr = ft_push_b(arr);
	return (arr);
}

static t_arr	ft_push_a(t_arr arr)
{
	t_list	*new;
	int		*num;

	if (!arr.array_b || !arr.array_b->content)
		return (arr);
	num = malloc(sizeof(int));
	*num = *((int *)arr.array_b->content);
	new = ft_lstnew(num);
	ft_lstadd_front(&arr.array_a, new);
	ft_lstdelone(arr.array_b, &ft_delete);
	arr.array_b = arr.array_b->next;
	write(1, "pa\n", 3);
	return (arr);
}

static t_arr	ft_push_b(t_arr arr)
{
	t_list	*new;
	int		*num;

	if (!arr.array_a || !arr.array_a->content)
		return (arr);
	num = malloc(sizeof(int));
	*num = *((int *)arr.array_a->content);
	new = ft_lstnew(num);
	ft_lstadd_front(&arr.array_b, new);
	ft_lstdelone(arr.array_a, &ft_delete);
	arr.array_a = arr.array_a->next;
	write(1, "pb\n", 3);
	return (arr);
}
