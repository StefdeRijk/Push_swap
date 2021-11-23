#include "push_swap.h"
#include <stdio.h>
static t_arr	ft_algorithm(t_arr arr);

static t_arr	ft_init_array(t_arr arr, char *argv);

static int		is_sorted(t_arr arr);

static t_list	*is_max(t_arr arr);

int	main(int argc, char **argv)
{
	t_arr	arr;
	int		arguments;
	int		i;

	arguments = argc - 1;
	arr.array_b = NULL;
	if (argc <= 1 || !argv)
		return (0);
	while (arguments > 0)
	{
		arr = ft_init_array(arr, argv[arguments]);
		arguments--;
	}
	arr = ft_algorithm(arr);
	write(1, "\n", 1);
	i = 5;
	while (i > 0)
	{
		if (arr.array_a != NULL)
		{
			if (*((int *)arr.array_a->content))
			{
				printf("%i	", *((int *)arr.array_a->content));
				arr.array_a = arr.array_a->next;
			}
			else
			{
				arr.array_a = arr.array_a->next;
				if (*((int *)arr.array_a->content))
				{
					printf("%i	", *((int *)arr.array_a->content));
					arr.array_a = arr.array_a->next;
				}
			}
		}
		if (arr.array_b != NULL)
		{
			if (*((int *)arr.array_b->content))
			{
				printf("%i", *((int *)arr.array_b->content));
				arr.array_b = arr.array_b->next;
			}
		}
		printf("\n");
		i--;
	}
	return (0);
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
		arr.max = is_max(arr);
		if (ft_lstsize(arr.array_a) == 3)
			return (ft_len_three(arr));
		if (ft_lstsize(arr.array_a) == 5)
			return (ft_len_five(arr));
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

static int	is_sorted(t_arr arr)
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
