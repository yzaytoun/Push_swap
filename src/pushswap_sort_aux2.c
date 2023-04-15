/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort_aux2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:27:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/15 16:00:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION SORT AUX 2
//ANCHOR - Check if top element is larger than the next element in the list
void	ft_checkswap(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE)
		return ;
	if (vars->size_b >= 2 && vars->size_a >= 2)
	{
		if ((vars->top_a > vars->next_a) && (vars->top_b < vars->next_b))
			ft_printer(ft_swap_first_two(&stack_a)
				+ ft_swap_first_two(&stack_b));
		else if (vars->top_a > vars->next_a)
			ft_printer(ft_swap_first_two(&stack_a));
		else if (vars->top_b < vars->next_b)
			ft_printer(ft_swap_first_two(&stack_b));
	}
	else if (vars->size_a >= 2)
	{
		if (vars->top_a > vars->next_a)
			ft_printer(ft_swap_first_two(&stack_a));
	}
}

//ANCHOR - Check if top element is the maximum
void	ft_checkrotate(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE)
		return ;
	if (vars->size_b >= 2 && vars->size_a >= 2)
	{	
		if ((vars->top_a == vars->max_a) && (vars->top_b == vars->min_b))
			ft_printer(ft_swap_rotate(&stack_a) + ft_swap_rotate(&stack_b));
		else if ((vars->top_a > vars->last_a) && (vars->top_b < vars->last_b))
			ft_printer(ft_swap_rotate(&stack_a) + ft_swap_rotate(&stack_b));
		else if (vars->top_a > vars->last_a)
			ft_printer(ft_swap_rotate(&stack_a));
		else if (vars->top_b < vars->last_b)
			ft_printer(ft_swap_rotate(&stack_b));
	}
	else if ((vars->top_a > vars->last_a))
		ft_printer(ft_swap_rotate(&stack_a));
}

//ANCHOR - Check if the last element is the minimum
void	ft_checkreverse(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE)
		return ;
	if (vars->size_b >= 2 && vars->size_a >= 2)
	{
		if ((vars->last_a == vars->min_a) && (vars->last_b == vars->max_b))
			ft_printer(ft_swap_reverse_rotate(&stack_a)
				+ ft_swap_reverse_rotate(&stack_b));
		else if ((vars->last_a < vars->top_a) && (vars->last_b > vars->top_b))
			ft_printer(ft_swap_reverse_rotate(&stack_a)
				+ ft_swap_reverse_rotate(&stack_b));
		else if (vars->last_a < vars->top_a)
			ft_printer(ft_swap_reverse_rotate(&stack_a));
		else if (vars->last_b > vars->top_b)
			ft_printer(ft_swap_reverse_rotate(&stack_b));
		else if (vars->last_a < vars->revnext_a)
			ft_printer(ft_swap_reverse_rotate(&stack_a));
		else if (vars->last_b > vars->revnext_b)
			ft_printer(ft_swap_reverse_rotate(&stack_b));
	}
	else if (vars->last_a < vars->top_a)
		ft_printer(ft_swap_reverse_rotate(&stack_a));
	else if (vars->last_a < vars->revnext_a)
		ft_printer(ft_swap_reverse_rotate(&stack_a));
}

void	ft_checkmin(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE)
		return ;
	if (vars->min_a == vars->last_a && vars->size_a > 3)
	{
		ft_printer(ft_swap_reverse_rotate(&stack_a));
		if (ft_issorted(stack_a->stack, ASC) != TRUE)
			ft_printer(ft_swap_push(stack_b, stack_a));
	}
	else if (vars->min_a == vars->next_a && vars->size_a > 3)
	{
		ft_printer(ft_swap_first_two(&stack_a));
		if (ft_issorted(stack_a->stack, ASC) != TRUE)
			ft_printer(ft_swap_push(stack_b, stack_a));
	}
	else if (vars->min_a == vars->revnext_a && vars->size_a > 3)
	{
		ft_printer(ft_swap_reverse_rotate(&stack_a));
		ft_printer(ft_swap_reverse_rotate(&stack_a));
		if (ft_issorted(stack_a->stack, ASC) != TRUE)
			ft_printer(ft_swap_push(stack_b, stack_a));
	}
	else if (vars->last_a == vars->min_a)
		ft_printer(ft_swap_reverse_rotate(&stack_a));
}

void	ft_checkmax(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_issorted(stack_a->stack, ASC) == TRUE)
		return ;
	if (vars->size_b >= 2 && vars->size_a >= 2)
	{	
		if ((vars->top_a == vars->max_a) && (vars->top_b == vars->min_b))
			ft_printer(ft_swap_rotate(&stack_a) + ft_swap_rotate(&stack_b));
		else if (vars->top_a == vars->max_a)
			ft_printer(ft_swap_rotate(&stack_a));
	}
	else if (vars->next_a == vars->max_a)
	{
		ft_printer(ft_swap_rotate(&stack_a));
		ft_printer(ft_swap_rotate(&stack_a));
	}
	else if (vars->revnext_a == vars->max_a)
		ft_printer(ft_swap_reverse_rotate(&stack_a));
	else if (vars->top_a == vars->max_a)
		ft_printer(ft_swap_rotate(&stack_a));
}

//!SECTION