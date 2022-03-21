/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:25:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/20 20:55:41 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap2.h"

void	push_number(t_stack **lsta, t_stack **lstb)
{
	while (*lsta)
	{
		p_ab(lsta, lstb);
	}
}

t_stack	*partition_a(t_stack **lsta, t_stack **lstb, t_add *info)
{
	t_stack	*tail;
	t_stack	*last;
	t_stack	*tailend;
	int		pivot;
	int		i;
	int		len;

	last = info->tail;
	tailend = last->next;
	tail = NULL;
	i = 0;
	len = ft_stacksize_n(*lsta, last);
	pivot = find_median(*lsta, last);
	while (*lsta != last && (*lsta)->num != pivot)
	{
		if ((*lsta)->num < pivot)
		{
			p_ab(lsta, lstb);
			if (tail == NULL)
				tail = *lstb;
		}
		else
			i += r_ab(lsta);
	}
	if ((*lsta)->num < pivot)
	{
		p_ab(lsta, lstb);
		if (tail == NULL)
			tail = *lstb;
	}
	while (i-- > 0 && tailend)
		rr_ab(lsta);
	return (tail);
}

t_stack	*partition_b(t_stack **lsta, t_stack **lstb, t_add *info)
{
	t_stack	*tail;
	t_stack	*last;
	t_stack	*tailend;
	int		pivot;
	int		i;


	last = info->tail;
	tailend = last->next;
	tail = NULL;
	i = 0;
	pivot = find_median(*lsta, last);
	while (*lsta != last)
	{
		if ((*lsta)->num >= pivot)
		{
			p_ab(lsta, lstb);
			if (tail == NULL)
				tail = *lstb;
		}
		else
			i += r_ab(lsta);
	}
	if ((*lsta)->num >= pivot)
	{
		p_ab(lsta, lstb);
		if (tail == NULL)
			tail = *lstb;
	}
	len = i;
	while (i-- > 0 && tailend)
		rr_ab(lsta);
	return (tail);
}

void	sorting(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	t_stack	*taila;
	t_stack	*tailb;

	if ((*stka)->stk == 1)
	{
		tailb = partition_a(stka, stkb, *a);
		ft_add_front(b, ft_new_add(tailb));
		delete_add(a);
	}
	if ((*stka)->stk == 2)
	{
		taila = partition_b(stka, stkb, *b);
		ft_add_front(a, ft_new_add(taila));
		delete_add(b);
	}
}

void	sort(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	if (!*a && *stka)
		ft_add_front(a, ft_new_add(ft_stacklast(*stka)));
	if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) > 3)
		sorting(stka, stkb, a, b);
	else if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) == 3)
		three_case_part(stka, (*a)->tail);
	else if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) == 2)
		s_ab(stka);
	if (!*b && *stkb && issorted(*stka))
		ft_add_front(b, ft_new_add(ft_stacklast(*stkb)));
	if (issorted(*stka) && *stkb)
	{
		if (issorted(*stkb))
			push_number(stkb, stka);
		else
			sorting(stkb, stka, a, b);
	}
	if (!issorted(*stka) || *stkb)
		sort(stka, stkb, a, b);
}
