#include "push_swap.h"
#include <stdio.h>
static t_arr	ft_algorithm(t_arr arr);

static t_arr	ft_init_array(t_arr arr, char *argv);

void			ft_iter(void *content);

int				is_sorted(t_arr arr);

static t_list	*is_max(t_arr arr);

int	main(int argc, char **argv)
{
	t_arr	arr;
	int		arguments;

	arguments = argc - 1;
	arr.array_a = 0;
	arr.array_b = 0;
	if (argc <= 1 || !argv)
		return (0);
	while (arguments > 0)
	{
		arr = ft_init_array(arr, argv[arguments]);
		arguments--;
	}
	arr = ft_algorithm(arr);
	// write(1, "\n", 1);
	// ft_lstiter(arr.array_a, &ft_iter);
	// ft_lstiter(arr.array_b, &ft_iter);
	return (0);
}

// void	ft_iter(void *content)
// {
// 	int	*i;

// 	i = content;
// 	printf("%i\n", *i);
// }

static t_arr	ft_init_array(t_arr arr, char *argv)
{
	t_list	*new;
	int		*num;

	num = malloc(sizeof(int));
	if (!num)
		return (arr);
	*num = ft_atoi(argv);
	new = ft_lstnew(num);
	ft_lstadd_front(&arr.array_a, new);
	return (arr);
}

static t_arr	ft_algorithm(t_arr arr)
{
	arr.next_a = arr.array_a->next;
	arr.next_b = (t_list *)malloc(sizeof(t_list *));
	if (is_sorted(arr) == 0)
	{
		arr.max = is_max(arr);
		if (ft_lstsize(arr.array_a) <= 3)
			return (ft_len_three(arr, ft_lstsize(arr.array_a)));
		if (ft_lstsize(arr.array_a) <= 5)
			return (ft_len_five(arr, ft_lstsize(arr.array_a)));
		// else
		// 	return (ft_len_long(arr));
	}
	return (arr);
}

static t_list	*is_max(t_arr arr)
{
	t_list	*current;
	t_list	*max;

	current = arr.array_a;
	max = arr.array_a;
	while (current->next)
	{
		if (*((int *)current->content) > *((int *)max->content))
			max = current;
		current = current->next;
	}
	return (max);
}

int	is_sorted(t_arr arr)
{
	t_list	*copy;
	t_list	*next_elem;

	copy = arr.array_a;
	next_elem = arr.array_a->next;
	while (next_elem)
	{
		if (*((int *)copy->content) > *((int *)next_elem->content))
			return (0);
		next_elem = next_elem->next;
		copy = copy->next;
	}
	if (!arr.array_b)
		return (1);
	return (0);
}
