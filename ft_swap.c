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
	int		*temp;
	t_list	*temp_list;

	if (!array_a)
		return (array_a);
	temp_list = array_a;
	temp = array_a->content;
	temp_list = temp_list->next;
	array_a->content = temp_list->content;
	temp_list->content = temp;
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
