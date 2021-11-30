#include "push_swap.h"
t_arr	ft_push_a(t_arr arr)
{
	int		i;

	if (!arr.array_b)
		return (arr);
	i = arr.size - 1;
	while (i >= 0)
	{
		arr.array_a[i + 1] = arr.array_a[i];
		i--;
	}
	arr.array_a[0] = arr.array_b[0];
	i = 1;
	while (i < arr.size)
	{
		arr.array_b[i - 1] = arr.array_b[i];
		i++;
	}
	arr.array_b[arr.size - 1] = 0;
	arr.size_a += 1;
	arr.size_b -= 1;
	write(1, "pa\n", 3);
	return (arr);
}

t_arr	ft_push_b(t_arr arr)
{
	int	i;

	if (!arr.array_a)
		return (arr);
	i = arr.size - 1;
	while (i >= 0)
	{
		arr.array_b[i + 1] = arr.array_b[i];
		i--;
	}
	arr.array_b[0] = arr.array_a[0];
	i = 1;
	while (i < arr.size)
	{
		arr.array_a[i - 1] = arr.array_a[i];
		i++;
	}
	arr.array_a[arr.size - 1] = 0;
	arr.size_b += 1;
	arr.size_a -= 1;
	write(1, "pb\n", 3);
	return (arr);
}

t_arr	ft_rotate_a(t_arr arr)
{
	int	i;
	int	temp;

	if ((!arr.array_a && !arr.array_a[1]) || arr.size_a == 1)
		return (arr);
	i = 1;
	temp = arr.array_a[0];
	while (i < arr.size_a)
	{
		arr.array_a[i - 1] = arr.array_a[i];
		i++;
	}
	arr.array_a[arr.size_a - 1] = temp;
	write(1, "ra\n", 3);
	return (arr);
}

t_arr	ft_reverse_a(t_arr arr)
{
	int	i;
	int	temp;

	if (!arr.array_a)
		return (arr);
	i = arr.size_a - 1;
	temp = arr.array_a[arr.size_a - 1];
	while (i >= 0)
	{
		arr.array_a[i + 1] = arr.array_a[i];
		i--;
	}
	arr.array_a[0] = temp;
	write(1, "rra\n", 4);
	return (arr);
}

t_arr	ft_swap_a(t_arr arr)
{
	int	temp;

	if (!arr.array_a)
		return (arr);
	temp = arr.array_a[1];
	arr.array_a[1] = arr.array_a[0];
	arr.array_a[0] = temp;
	write(1, "sa\n", 3);
	return (arr);
}
