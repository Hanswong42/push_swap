/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:28:22 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/25 01:21:21 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_build(int argc, char **argv, t_stack **stka, t_stack **stkb)
{
	char	**hold;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		hold = ft_split(argv[i++], ' ');
		j = 0;
		while (hold[j])
		{
			if (!ft_checkdigit(hold[j]) || !ft_isover(hold[j]))
				return (error_message(stka, stkb, 0));
			stack_addback(stka, newstack(ft_atoi(hold[j++])));
		}
		free(hold);
	}
	return (1);
}
