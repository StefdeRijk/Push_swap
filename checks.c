#include "push_swap.h"
void	ft_check_arguments(char *str, t_arr arr)
{
	long	nbr;
	int		min;

	nbr = 0;
	min = 1;
	if (*str == '-')
		min = -1;
	while (*str)
	{
		if (*str != '-' && !(*str >= '0' && *str <= '9'))
			ft_error(arr);
		if ((*str >= '0' && *str <= '9'))
		{
			nbr *= 10;
			nbr += *str - '0';
		}
		if (nbr > 2147483648)
			ft_error(arr);
		str++;
	}
	nbr *= min;
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_error(arr);
}

void	ft_check_doubles(int *array, int len, t_arr arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < len - 1)
	{
		while (i < len)
		{
			if (array[i] == array[j])
				ft_error(arr);
			i++;
		}
		j++;
		i = j + 1;
	}
}
