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
}	t_arr;

t_arr	ft_swap(t_arr arr, char operation);
t_arr	ft_push(t_arr arr, char operation);
t_arr	ft_rotate(t_arr arr, char operation);
t_arr	ft_reverse(t_arr arr, char operation);
void	ft_delete(void *content);
t_arr	ft_len_three(t_arr arr);
t_arr	ft_len_five(t_arr arr);

#endif