#include "push_swap.h"
static char	*ft_bin_conversion(int n);

int	is_max_bin(t_arr arr)
{
	t_list	*current;
	int		max_len;
	char	*bin;

	current = arr.array_a;
	arr.max = arr.array_a;
	max_len = 0;
	while (current->next)
	{
		if (*((int *)current->content) > *((int *)arr.max->content))
			arr.max = current;
		current = current->next;
	}
	if (*((int *)current->content) > *((int *)arr.max->content))
		arr.max = current;
	bin = ft_bin_conversion(*((int *)arr.max->content));
	while (bin[max_len])
		max_len++;
	return (max_len);
}

static char	*ft_bin_conversion(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_numlen(n);
	str = ft_calloc(len * sizeof(char) + 1, 1);
	while (nbr > 0)
	{
		len--;
		str[len] = nbr % 2 + '0';
		nbr /= 2;
	}
	return (str);
}

t_list	*is_max(t_arr arr)
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
