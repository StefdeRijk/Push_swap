#include "push_swap.h"
static t_list	*ft_swap_a(t_list *array_a, int print);

static t_list	*ft_swap_b(t_list *array_b, int print);

static t_arr	ft_swap_both(t_arr arr);

t_arr	ft_swap(t_arr arr, char operation)
{
	if (operation == 'a')
		arr.array_a = ft_swap_a(arr.array_a, 1);
	else if (operation == 'b')
		arr.array_b = ft_swap_b(arr.array_b, 1);
	else if (operation == 's')
		arr = ft_swap_both(arr);
	return (arr);
}

static t_list	*ft_swap_a(t_list *array_a, int print)
{
	t_list	*copy;
	t_list	*copy_before;
	t_list	*new;
	int		*num;

	if (!array_a)
		return (array_a);
	copy = (t_list *)malloc(sizeof(t_list *));
	num = malloc(sizeof(int));
	if (!copy || ! num)
		return (array_a);
	copy = array_a->next;
	copy_before = array_a;
	*num = *((int *)copy->content);
	new = ft_lstnew(num);
	ft_lstadd_front(&array_a, new);
	ft_lstdelone(copy, &ft_delete);
	copy = copy->next;
	copy_before->next = copy;
	if (print == 1)
		write(1, "sa\n", 3);
	return (array_a);
}

static t_list	*ft_swap_b(t_list *array_b, int print)
{
	int		*temp;
	t_list	*temp_list;

	if (!array_b)
		return (array_b);
	temp_list = array_b;
	temp = array_b->content;
	temp_list = temp_list->next;
	array_b->content = temp_list->content;
	temp_list->content = temp;
	if (print == 1)
		write(1, "sb\n", 3);
	return (array_b);
}

static t_arr	ft_swap_both(t_arr arr)
{
	if (!arr.array_a && !arr.array_b)
		return (arr);
	if (arr.array_a)
		arr.array_a = ft_swap_a(arr.array_a, 0);
	if (arr.array_b)
		arr.array_b = ft_swap_b(arr.array_b, 0);
	write(1, "ss\n", 3);
	return (arr);
}
