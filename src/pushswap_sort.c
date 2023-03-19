/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:10:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/19 17:18:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - Sort
//ANCHOR - First check
void	ft_first_check(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (vars->top_a > stack_a->stack->next->content)
		vars->signal = ft_swap_first_two(&stack_a);
	else if (vars->top_b > stack_b->stack->next->content)
		vars->signal = ft_swap_first_two(&stack_b);
	if ((vars->top_a > stack_a->stack->next->content)
		&& (vars->top_b > stack_b->stack->next->content))
		vars->signal = ft_swap_first_two(&stack_a)
			+ ft_swap_first_two(&stack_b);
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
}

//ANCHOR - Sort Stack
void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b, int maxsteps)
{
	t_stack		*node;
	t_variables	*vars;

	if (ft_isempty(stack_a))
		return ;
	vars = ft_calloc(1, sizeof(t_variables));
	if (!vars)
		return ;
	vars->size_a = ft_stacksize(stack_a);
	while (ft_issorted(stack_a, ASC) != TRUE
		&& ft_stacksize(stack_a) != vars->size_a)
	{
		if (vars->steps > maxsteps)
		{
			ft_printf("\n******* Number of steps exceeded *******\n");
			return ;
		}
		ft_setvariables(stack_a, stack_b, vars);
		ft_printer(ft_firstcheck(/*variables*/));
		vars->steps++;
	}
	free(vars);
}
//!SECTION