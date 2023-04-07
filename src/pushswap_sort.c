/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:10:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/07 10:50:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - SORT
//ANCHOR - First rotation
static void	ft_sortloop(t_stack *stack_1, t_stack *stack_2, t_variables *vars)
{
	ft_setvariables(stack_1, stack_2, vars);
	ft_printer(ft_checkrotate(stack_1, stack_2, vars));
	ft_setvariables(stack_1, stack_2, vars);
	ft_printer(ft_checkswap(stack_1, stack_2, vars));
	ft_setvariables(stack_1, stack_2, vars);
	ft_printer(ft_checkreverse(stack_1, stack_2, vars));
	ft_setvariables(stack_1, stack_2, vars);
	ft_printer(ft_checkpush(stack_1, stack_2, vars));
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
	vars->size_a = ft_lstsize(stack_a->stack);
	vars->size_b = ft_lstsize(stack_b->stack);
	vars->signal = 0;
	vars->steps++;
}

//ANCHOR - Sort Stack
void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_variables	*vars;

	if (ft_isempty(stack_a->stack))
		return ;
	vars = ft_calloc(1, sizeof(t_variables));
	if (!vars)
		return ;
	vars->full_size = ft_lstsize(stack_a->stack);
	if (vars->full_size == 1)
		return ;
	while (ft_issorted(stack_a->stack, ASC) != TRUE)
		ft_sortloop(stack_a, stack_b, vars);
	while (ft_isempty(stack_b->stack) != TRUE)
		ft_sortloop(stack_a, stack_b, vars);
	if (ft_issorted(stack_a->stack, ASC) != TRUE)
		while (ft_issorted(stack_a->stack, ASC) != TRUE)
			ft_sortloop(stack_a, stack_b, vars);
	if (ft_isempty(stack_b->stack) != TRUE
		&& ft_issorted(stack_b->stack, DESC) == TRUE)
		while (ft_isempty(stack_b->stack) != TRUE)
			ft_printer(ft_swap_push(stack_a, stack_b));
	free(vars);
}
//!SECTION