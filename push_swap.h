/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:00:59 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 01:26:50 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	int				num;
	int				stk;
	struct s_stack	*next;
}	t_stack;

typedef struct s_add {
	int				len;
	struct s_stack	*tail;
	struct s_add	*nxt;
}	t_add;

t_stack	*newstack(int n);
int		ft_stacksize(t_stack *lst);
void	stack_addback(t_stack **lst, t_stack *new);
int		ft_stacksize_n(t_stack *lst, t_stack *last);
void	stack_addback(t_stack **lst, t_stack *new);
void	bubble_sort(int *arr, int size);
int		find_median(t_stack *lst, int size);
int		ft_stacksize_n(t_stack *lst, t_stack *last);
t_stack	*ft_stacklast(t_stack *stk);
t_stack	*ft_iter_stop(t_stack *stk, t_stack *last);
int		r_ab(t_stack **stack);
int		p_ab(t_stack **stacka, t_stack **stackb);
int		rr_ab(t_stack **stack);
int	s_ab(t_stack **lst);
t_add	*ft_new_add(t_stack *tail, int len);
void	*ft_add_front(t_add **list, t_add *new);
t_stack	*find_highest(t_stack *lst, t_stack *last);
t_stack	*find_lowest(t_stack *lst, t_stack *last);
void	three_case_part(t_stack **lst, t_stack *last);
void	three_case(t_stack **lst, t_stack *last);
t_stack	*partition_a(t_stack **lsta, t_stack **lstb, t_add *a);
t_stack	*partition_b(t_stack **lsta, t_stack **lstb, t_add *b);
void	sorting(t_stack **stka, t_stack **stkb, t_add **a, t_add **b);
void	sort(t_stack **stka, t_stack **stkb, t_add **a, t_add **b);
int		issorted(t_stack *lst);
void	delete_add(t_add **add);
int	issortedtail(t_stack *lst, int len);
#endif