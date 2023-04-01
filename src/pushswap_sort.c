/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:10:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/01 16:59:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - Sort
//ANCHOR - Check if top element is larger than the next element in the list
int	ft_checktop(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_isempty(stack_b->stack) == FALSE
		&& ft_lstsize(stack_b->stack) >= 2 && vars->size_a >= 2)
	{
		if ((vars->top_a > (int)stack_a->stack->next->content)
			&& (vars->top_b < (int)stack_b->stack->next->content))
			vars->signal = ft_swap_first_two(&stack_a)
				+ ft_swap_first_two(&stack_b);
		else if (vars->top_b < (int)stack_b->stack->next->content)
			vars->signal = ft_swap_first_two(&stack_b);
		else if (vars->top_a > (int)stack_a->stack->next->content)
			vars->signal = ft_swap_first_two(&stack_a);
	}
	else if (vars->size_a >= 2)
	{
		if (vars->top_a > (int)stack_a->stack->next->content)
			vars->signal = ft_swap_first_two(&stack_a);
	}
	else
		vars->signal = 0;
	return (vars->signal);
}

//ANCHOR - Check if top element is the maximum
int	ft_checkmax(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_isempty(stack_b->stack) == FALSE
		&& ft_lstsize(stack_b->stack) >= 2)
	{	
		if ((vars->top_a == vars->max_a) && (vars->top_b == vars->min_b))
			vars->signal = ft_swap_rotate(&stack_a) + ft_swap_rotate(&stack_b);
		else if (vars->top_b == vars->min_b)
			vars->signal = ft_swap_rotate(&stack_b);
		else if (vars->top_a == vars->max_a)
			vars->signal = ft_swap_rotate(&stack_a);
	}
	else if (vars->top_a == vars->max_a)
		vars->signal = ft_swap_rotate(&stack_a);
	else
		vars->signal = 0;
	return (vars->signal);
}

//ANCHOR - Check if the last element is the minimum
int	ft_checkmin(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (ft_isempty(stack_b->stack) == FALSE
		&& ft_lstsize(stack_b->stack) >= 2)
	{
		if ((vars->last_a == vars->min_a) && (vars->last_b == vars->max_b))
			vars->signal = ft_swap_reverse_rotate(&stack_a)
				+ ft_swap_reverse_rotate(&stack_b);
		else if (vars->last_b == vars->max_b)
			vars->signal = ft_swap_reverse_rotate(&stack_b);
		else if (vars->last_a == vars->min_a)
			vars->signal = ft_swap_reverse_rotate(&stack_a);
	}
	else if (vars->last_a == vars->min_a)
		vars->signal = ft_swap_reverse_rotate(&stack_a);
	else
		vars->signal = 0;
	return (vars->signal);
}

//ANCHOR - Set variables
void	ft_setvariables(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	vars->max_a = ft_getmax(stack_a->stack);
	vars->min_a = ft_getmin(stack_a->stack);
	vars->top_a = ft_gettop(stack_a->stack);
	vars->last_a = ft_getlast(stack_a->stack);
	vars->max_b = ft_getmax(stack_b->stack);
	vars->min_b = ft_getmin(stack_b->stack);
	vars->top_b = ft_gettop(stack_b->stack);
	vars->last_b = ft_getlast(stack_b->stack);
	vars->size_a = ft_lstsize((stack_a)->stack);
}

//ANCHOR - Sort Stack
void	ft_sort_stack(t_stack **stack_a, t_stack *stack_b)
{
	t_variables	*vars;

	if (ft_isempty((*stack_a)->stack))
		return ;
	vars = ft_calloc(1, sizeof(t_variables));
	if (!vars)
		return ;
	vars->full_size = ft_lstsize((*stack_a)->stack);
	if (vars->full_size == 1)
		return ;
	while (vars->flag != 1)
	{
		ft_setvariables(*stack_a, stack_b, vars);
		ft_printer(ft_checktop(*stack_a, stack_b, vars));
		ft_printer(ft_checkmax(*stack_a, stack_b, vars));
		ft_printer(ft_checkmin(*stack_a, stack_b, vars));
		vars->signal = 0;
		ft_finalcheck(*stack_a, stack_b, vars);
		vars->steps++;
	}
	free(vars);
}
//!SECTION