#include "push_swap.h"
int	is_max(t_arr arr)
{
	int	i;
	int	max;

	i = 0;
	max = arr.sorted_pos[i];
	while (i < arr.size - 1)
	{
		if (arr.sorted_pos[i] > max)
			max = arr.sorted_pos[i];
		i++;
	}
	return (max);
}

int	is_sorted(t_arr arr)
{
	int	i;

	i = 0;
	while (i < arr.size - 1)
	{
		if (arr.array_a[i] > arr.array_a[i + 1])
			return (0);
		i++;
	}
	i = 0;
	if (arr.size_b == 0)
		return (1);
	return (0);
}

int	ft_numlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		nbr = nbr / 2;
		i++;
	}
	return (i);
}
