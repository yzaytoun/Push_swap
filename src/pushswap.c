/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:26:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/10 20:43:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - SORT ALGO
//ANCHOR - Measure distance
int	ft_getpos_rev(t_list *stac, int num)
{
	t_list	*top;
	int		pos;

	pos = 0;
	if (ft_isempty(stac))
		return (0);
	top = ft_copylist(stac);
	ft_reverse_stack(&top);
	while (top != NULL)
	{
		if ((int)top->content == num)
			break ;
		++pos;
		top = top->next;
	}
	return (pos);
}

//ANCHOR - Suffle stack
void	ft_shuffle(
	t_stack *stack_a, t_stack *stack_b, t_variables *vars, t_list *sorted)
{
	while (sorted != NULL && ft_lstsize(sorted) > 5)
	{
		vars->curr = (int)sorted->content;
		ft_setvariables(stack_a, stack_b, vars);
		while (vars->top_a != vars->curr)
		{
			if (ft_getpos(stack_a->stack, vars->curr)
				> ft_getpos_rev(stack_a->stack, vars->curr))
				ft_printer(ft_swap_reverse_rotate(&stack_a));
			else
				ft_printer(ft_swap_rotate(&stack_a));
			ft_setvariables(stack_a, stack_b, vars);
		}
		ft_printer(ft_swap_push(stack_b, stack_a));
		sorted = sorted->next;
	}
	ft_sortstack(stack_a, stack_b);
}

//ANCHOR - SORT ALGO
void	ft_sortalgo(t_stack *stack_a, t_stack *stack_b)
{
	t_variables	*vars;
	t_list		*sorted;

	if (ft_isempty(stack_a->stack))
		return ;
	vars = ft_calloc(1, sizeof(t_variables));
	if (!vars)
		return ;
	sorted = NULL;
	vars->full_size = ft_lstsize(stack_a->stack);
	if (vars->full_size == 1)
		return ;
	sorted = ft_copylist(stack_a->stack);
	ft_mergesort(&sorted);
	ft_shuffle(stack_a, stack_b, vars, sorted);
	free(vars);
}
//!SECTION