/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:10:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/14 19:53:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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

int	ft_firstcheck(t_stack *stack_a, t_stack *stack_b)
{
	int	signal;
	int	i;

	i = -1;
	if (ft_gettop(stack_a) == ft_getmax(stack_a))
		signal = ft_swap_rotate(&stack_a);
	else if (ft_getlast(stack_a) == ft_getmin(stack_a))
		signal = ft_swap_reverse_rotate(&stack_a);
	else
	{
		if (ft_getpos(stack_a, ft_getmax(stack_a) != ft_stacksize(stack_a)))
		{
			while (++i < ft_getpos(stack_a, ft_getmax(stack_a)))
			{
				ft_swap_push(&stack_b, &stack_a);
				ft_printf("PB\n");
			}
		}
	}
	return (signal);
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b, int maxsteps)
{
	t_stack	*node;
	int		steps;

	steps = 0;
	if (ft_isempty(stack_a))
		return ;
	while (ft_issorted(stack_a, ASC) != TRUE)
	{
		if (steps > maxsteps)
		{
			ft_printf("\n******* Number of steps exceeded *******\n");
			return ;
		}
		ft_printter(ft_firstcheck(stack_a, stack_b));
		steps++;
	}
}
