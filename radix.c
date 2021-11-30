#include "push_swap.h"
static t_arr	ft_sort_array(t_arr arr);

static t_arr	ft_sorted_array(t_arr arr);

static t_arr	ft_get_pos(t_arr arr);

t_arr	ft_radix(t_arr arr)
{
	arr = ft_sorted_array(arr);
	arr = ft_get_pos(arr);
	arr.max = is_max(arr);
	arr = ft_sort_array(arr);
	return (arr);
}

static t_arr	ft_sort_array(t_arr arr)
{
	int		i;
	int		power;
	int		exp;

	i = 0;
	exp = 0;
	power = ft_numlen(arr.max);
	while (exp < power)
	{
		arr = ft_get_pos(arr);
		while (i < arr.size)
		{
			if ((arr.sorted_pos[i] & (1 << exp)) == 0)
				arr = ft_push_b(arr);
			else
				arr = ft_rotate_a(arr);
			i++;
		}
		while (arr.size_b > 0)
			arr = ft_push_a(arr);
		i = 0;
		exp++;
	}
	return (arr);
}

static t_arr	ft_sorted_array(t_arr arr)
{
	int	i;
	int	swap;
	int	temp;

	i = 0;
	swap = 1;
	while (swap != 0)
	{
		swap = 0;
		while (i < arr.size - 1)
		{
			if (arr.sorted_array[i] > arr.sorted_array[i + 1])
			{
				swap++;
				temp = arr.sorted_array[i];
				arr.sorted_array[i] = arr.sorted_array[i + 1];
				arr.sorted_array[i + 1] = temp;
			}
			i++;
		}
		i = 0;
	}
	return (arr);
}

static t_arr	ft_get_pos(t_arr arr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < arr.size)
	{
		while (i < arr.size)
		{
			if (arr.sorted_array[i] == arr.array_a[j])
				arr.sorted_pos[j] = i;
			i++;
		}
		i = 0;
		j++;
	}
	return (arr);
}
