#include "push_swap.h"
#include <stdio.h>
static t_arr	ft_algorithm(t_arr arr);

static t_arr	ft_init_array(t_arr arr, char *argv);

void			ft_iter(void *content);

int	main(int argc, char **argv)
{
	t_arr	arr;
	int		arguments;

	arguments = argc - 1;
	arr.size = arguments;
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
	write(1, "\n", 1);
	ft_lstiter(arr.array_a, &ft_iter);
	ft_lstiter(arr.array_b, &ft_iter);
	return (0);
}

void	ft_iter(void *content)
{
	int	*i;

	i = content;
	printf("%i\n", *i);
}

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
		if (ft_lstsize(arr.array_a) <= 3)
			return (ft_len_three(arr, ft_lstsize(arr.array_a)));
		if (ft_lstsize(arr.array_a) <= 5)
			return (ft_len_five(arr, ft_lstsize(arr.array_a)));
		else
			return (ft_radix(arr));
	}
	return (arr);
}
