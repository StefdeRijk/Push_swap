#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_arr
{
	t_list	*array_a;
	t_list	*array_b;
	t_list	*next_a;
	t_list	*next_b;
	t_list	*max;
	t_list	*min;
	int		*sorted_array;
	int		*sorted_pos;
	char	**binary;
	int		size;
	int		max_len;
}	t_arr;

t_arr	ft_swap(t_arr arr, char operation);
t_arr	ft_push(t_arr arr, char operation);
t_arr	ft_rotate(t_arr arr, char operation);
t_arr	ft_reverse(t_arr arr, char operation);
void	ft_delete(void *content);
t_arr	ft_len_three(t_arr arr, int size);
t_arr	ft_len_five(t_arr arr, int size);
int		is_sorted(t_arr arr);
t_arr	ft_len_long(t_arr arr);
void	ft_iter(void *content);
t_arr	is_min(t_arr arr);
t_list	*is_max(t_arr arr);
int		ft_numlen(int nbr);
t_arr	ft_radix(t_arr arr);
char	*ft_numcpy_bin(int n, t_arr arr);
int		is_max_bin(t_arr arr);

#endif