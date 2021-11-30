#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_arr
{
	int		*array_a;
	int		*array_b;

	int		min;
	int		min_pos;
	int		max;

	int		*sorted_array;
	int		*sorted_pos;

	int		size;
	int		size_a;
	int		size_b;
}	t_arr;

void	ft_check_arguments(char *str, t_arr arr);
void	ft_check_doubles(int *array, int len, t_arr arr);

t_arr	ft_push_a(t_arr arr);
t_arr	ft_push_b(t_arr arr);
t_arr	ft_rotate_a(t_arr arr);
t_arr	ft_reverse_a(t_arr arr);
t_arr	ft_swap_a(t_arr arr);

t_arr	ft_len_three(t_arr arr, int size);
t_arr	ft_len_five(t_arr arr, int size);
t_arr	ft_radix(t_arr arr);

int		is_sorted(t_arr arr);
t_arr	is_min(t_arr arr);
int		is_max(t_arr arr);
int		ft_numlen(int nbr);

void	ft_error(t_arr arr);

#endif