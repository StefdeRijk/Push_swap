#include "push_swap.h"
#include <stdio.h>
static t_arr	ft_convert_binary(t_arr arr);

static t_arr	ft_sort_array(t_arr arr);

t_arr	ft_radix(t_arr arr)
{
	t_list	*copy;

	copy = arr.array_a;
	arr.binary = ft_calloc(ft_lstsize(arr.array_a) * sizeof(char *) + 1, 1);
	arr = ft_convert_binary(arr);
	arr = ft_sort_array(arr);
	return (arr);
}

static t_arr	ft_convert_binary(t_arr arr)
{
	t_list	*copy;
	int		i;

	copy = arr.array_a;
	arr.max = is_max(arr);
	arr.max_len = ft_numlen(*((int *)arr.max->content));
	i = 0;
	while (i < ft_lstsize(arr.array_a))
	{
		arr.binary[i] = ft_numcpy_bin(*((int *)copy->content), arr);
		printf("%s\n", arr.binary[i]);
		copy = copy->next;
		i++;
	}
	return (arr);
}

char	*ft_numcpy_bin(int n, t_arr arr)
{
	int		len;
	long	nbr;
	char	*str;

	len = is_max_bin(arr);
	nbr = n;
	str = ft_calloc(len * sizeof(char) + 1, 1);
	while (nbr > 0)
	{
		len--;
		str[len] = nbr % 2 + '0';
		nbr /= 2;
	}
	while (len > 0)
	{
		len--;
		str[len] = '0';
	}
	return (str);
}

static t_arr	ft_sort_array(t_arr arr)
{
	t_list	*copy;
	int		i;
	int		j;

	copy = arr.array_a;
	i = 0;
	j = arr.max_len - 1;
	while (j >= 0)
	{
		while (i < arr.size)
		{
			if (arr.binary[i][j] == '0')
				arr = ft_push(arr, 'b');
			else
				arr = ft_rotate(arr, 'a');
			i++;
		}
		while (arr.array_b)
			arr = ft_push(arr, 'a');
		arr = ft_convert_binary(arr);
		j--;
		i = 0;
	}
	return (arr);
}
