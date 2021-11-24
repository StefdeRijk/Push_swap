#include "push_swap.h"
#include <stdio.h>
static t_arr	ft_reverse_a(t_arr arr, int print);

static t_arr	ft_reverse_b(t_arr arr, int print);

static t_arr	ft_reverse_both(t_arr arr);

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
	t_list	*copy;
	t_list	*copy_next;
	t_list	*new;
	int		*num;

	if (!arr.array_a)
		return (arr);
	copy = arr.array_a;
	copy_next = (t_list *)malloc(sizeof(t_list *));
	copy_next = arr.array_a->next;
	while (copy_next->next)
	{
		copy = copy->next;
		copy_next = copy_next->next;
	}
	num = malloc(sizeof(int));
	*num = *((int *)copy_next->content);
	new = ft_lstnew(num);
	ft_lstadd_front(&arr.array_a, new);
	ft_lstdelone(copy_next, &ft_delete);
	copy->next = NULL;
	arr = is_min(arr);
	if (print == 1)
		write(1, "rra\n", 4);
	return (arr);
}

static t_arr	ft_reverse_b(t_arr arr, int print)
{
	t_list	*copy;
	t_list	*copy_next;
	t_list	*new;
	int		*num;

	if (!arr.array_b)
		return (arr);
	copy = arr.array_b;
	copy_next = (t_list *)malloc(sizeof(t_list *));
	copy_next = arr.array_b->next;
	while (copy_next->next)
	{
		copy = copy->next;
		copy_next = copy_next->next;
		printf("%i\n\n", *((int *)copy_next->content));
	}
	num = malloc(sizeof(int));
	*num = *((int *)copy_next->content);
	new = ft_lstnew(num);
	ft_lstadd_front(&arr.array_b, new);
	ft_lstdelone(copy_next, &ft_delete);
	copy->next = NULL;
	arr = is_min(arr);
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
