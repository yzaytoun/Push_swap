/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:10:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/16 20:29:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
/*
int	ft_secondcheck(t_stack *stack_a, t_stack *stack_b)
{
	int	signal;

	if (ft_isempty(stack_a) == FALSE && ft_stacksize(stack_b) > 1)
	{
		if (ft_gettop(stack_a) == ft_getmax(stack_a)
			&& ft_getlast(stack_b) == ft_getmax(stack_b))
			signal = ft_swap_rotate(&stack_a);
		else if (ft_getlast(stack_a) == ft_getmin(stack_a))
			signal = ft_swap_reverse_rotate(&stack_a);
	}
	return (signal);
}

//ANCHOR - Check for max and min
int	ft_max_min(t_stack *stack_a, t_stack *stack_b)
{
	int	signal;
	int	i;

	i = -1;
	signal = 0;
	if (ft_gettop(stack_a) == ft_getmax(stack_a))
		signal = ft_swap_rotate(&stack_a);
	else if (ft_getlast(stack_a) == ft_getmin(stack_a))
		signal = ft_swap_reverse_rotate(&stack_a);
	if (ft_gettop(stack_a) == ft_getmax(stack_a)
		&& ft_getlast(stack_b) == ft_getmax(stack_b))
		signal = ft_swap_rotate(&stack_a) + ft_swap_rotate(&stack_b);
	else if (ft_getlast(stack_a) == ft_getmin(stack_a)
		&& ft_gettop(stack_b) == ft_getmin(stack_b))
		signal = ft_swap_reverse_rotate(&stack_a)
			+ ft_swap_reverse_rotate(&stack_b);
	return (signal);
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b, int maxsteps)
{
	t_stack	*node;
	int		steps;
	int		size;

	steps = 0;
	if (ft_isempty(stack_a))
		return ;
	size = ft_stacksize(stack_a);
	while (ft_issorted(stack_a, ASC) != TRUE && ft_stacksize(stack_a) != size)
	{
		if (steps > maxsteps)
		{
			ft_printf("\n******* Number of steps exceeded *******\n");
			return ;
		}
		ft_printer(ft_max_min(stack_a, stack_b));
		ft_printer(ft_secondcheck(stack_a, stack_b));
		//ft_printer(ft_thirdcheck(stack_a, stack_b));
		steps++;
	}
}
*/