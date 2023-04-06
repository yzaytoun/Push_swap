/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort_aux2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:27:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/06 17:18:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION SORT AUX 2
//ANCHOR - Check if top element is larger than the next element in the list
int	ft_checkswap(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE && stack_a->index == 1
		&& ft_isempty(stack_b->stack) == TRUE)
		return (0);
	if (vars->size_b >= 2 && vars->size_a >= 2)
	{
		if ((vars->top_a > (int)stack_a->stack->next->content)
			&& (vars->top_b < (int)stack_b->stack->next->content))
			vars->signal = ft_swap_first_two(&stack_a)
				+ ft_swap_first_two(&stack_b);
		else if (vars->top_a > (int)stack_a->stack->next->content)
			vars->signal = ft_swap_first_two(&stack_a);
	}
	else if (vars->size_a >= 2)
	{
		if (vars->top_a > (int)stack_a->stack->next->content)
			vars->signal = ft_swap_first_two(&stack_a);
	}
	return (vars->signal);
}

//ANCHOR - Check if top element is the maximum
int	ft_checkrotate(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE && stack_a->index == 1
		&& ft_isempty(stack_b->stack) == TRUE)
		return (0);
	if (vars->size_b >= 2 && vars->size_a >= 2)
	{	
		if ((vars->top_a == vars->max_a) && (vars->top_b == vars->min_b))
			vars->signal = ft_swap_rotate(&stack_a) + ft_swap_rotate(&stack_b);
		else if ((vars->top_a > vars->last_a) && (vars->top_b < vars->last_b))
			vars->signal = ft_swap_rotate(&stack_a) + ft_swap_rotate(&stack_b);
		else if (vars->top_a == vars->max_a || vars->top_a > vars->last_a)
			vars->signal = ft_swap_rotate(&stack_a);
	}
	else if (vars->top_a == vars->max_a || vars->top_a > vars->last_a)
		vars->signal = ft_swap_rotate(&stack_a);
	return (vars->signal);
}

//ANCHOR - Check if the last element is the minimum
int	ft_checkreverse(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE && stack_a->index == 1
		&& ft_isempty(stack_b->stack) == TRUE)
		return (0);
	if (vars->size_b >= 2 && vars->size_a >= 2)
	{
		if ((vars->last_a == vars->min_a) && (vars->last_b == vars->max_b))
			vars->signal = ft_swap_reverse_rotate(&stack_a)
				+ ft_swap_reverse_rotate(&stack_b);
		else if ((vars->last_a < vars->top_a) && (vars->last_b > vars->top_b))
			vars->signal = ft_swap_reverse_rotate(&stack_a)
				+ ft_swap_reverse_rotate(&stack_b);
		else if (vars->last_a == vars->min_a || vars->last_a < vars->top_a)
			vars->signal = ft_swap_reverse_rotate(&stack_a);
	}
	else if (vars->last_a == vars->min_a || vars->last_a < vars->top_a)
		vars->signal = ft_swap_reverse_rotate(&stack_a);
	return (vars->signal);
}

//ANCHOR - FULL CHECK
int	ft_checkpush(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE && stack_a->index == 1
		&& ft_isempty(stack_b->stack) == TRUE)
		return (0);
	if (ft_issorted(stack_a->stack, ASC) == TRUE
		&& vars->size_a != vars->full_size)
		vars->signal = ft_swap_push(stack_a, stack_b);
	else if (ft_issorted(stack_a->stack, ASC) != TRUE)
		vars->signal = ft_swap_push(stack_b, stack_a);
	return (vars->signal);
}

//!SECTION