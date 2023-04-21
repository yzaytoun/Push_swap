/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:26:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/21 16:58:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - SORT ALGO
//ANCHOR - Sort Only B
void	ft_checkpos(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	if (vars->top_a > vars->next_a && vars->top_b < vars->next_b)
		ft_printer(ft_swap_first_two(&stack_a) + ft_swap_first_two(&stack_b));
	ft_checkpoint(stack_a, stack_b, vars);
	if (vars->top_a > vars->next_a)
		ft_printer(ft_swap_first_two(&stack_a));
	ft_checkpoint(stack_a, stack_b, vars);
	if (vars->top_b < vars->next_b)
		ft_printer(ft_swap_first_two(&stack_b));
	ft_checkpoint(stack_a, stack_b, vars);
}

//ANCHOR - PUSH TO B
void	ft_pushtob(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	ft_checkpos(stack_a, stack_b, vars);
	ft_printer(ft_swap_push(stack_a, stack_b));
	ft_checkpoint(stack_a, stack_b, vars);
	while (ft_issorted(stack_a->stack, ASC) != TRUE)
	{
		ft_checkpos(stack_a, stack_b, vars);
		ft_checkpoint(stack_a, stack_b, vars);
		ft_sortloop(stack_a, stack_b, vars);
		ft_checkpoint(stack_a, stack_b, vars);
	}
}

//ANCHOR - GET Chunk - get ordered chunk and extract the closet number
int	ft_getchunk(t_list *sorted, t_stack *stack,
	int (*func)(t_list *, int), t_variables *vars)
{
	int		count;
	int		min_pos;
	int		limit;

	count = 0;
	if (vars->full_size <= 100)
		limit = 5;
	if (vars->full_size > 100)
		limit = 13;
	if (ft_searchstack(stack->stack, (int)sorted->content) == TRUE)
		min_pos = func(stack->stack, (int)sorted->content);
	while (count < limit && sorted != NULL)
	{
		if (ft_searchstack(stack->stack, (int)sorted->content) == TRUE)
		{
			if (min_pos > func(stack->stack, (int)sorted->content))
				min_pos = func(stack->stack, (int)sorted->content);
		}
		sorted = sorted->next;
		++count;
	}
	return (min_pos);
}

//ANCHOR - Suffle stack
static void	ft_shuffle(t_stack *stack_a, t_stack *stack_b,
	t_variables *vars, t_list *sorted)
{
	int		(*func[2])(t_list *, int);

	func[0] = &ft_getpos;
	func[1] = &ft_getpos_rev;
	ft_checkpoint(stack_a, stack_b, vars);
	while (vars->size_a > 15)
	{
		sorted = ft_copylist(stack_a->stack);
		ft_mergesort(&sorted);
		vars->currpos = ft_getchunk(sorted, stack_a, func[0], vars);
		vars->currrevpos = ft_getchunk(sorted, stack_a, func[1], vars);
		if (vars->currpos > vars->currrevpos)
			vars->curr = ft_getnum(stack_a->stack, vars->currrevpos, BACKWARD);
		else
			vars->curr = ft_getnum(stack_a->stack, vars->currpos, FORWARD);
		ft_checkpoint(stack_a, stack_b, vars);
		ft_getnext_element(stack_a, stack_b, vars);
		ft_checkpos(stack_a, stack_b, vars);
		ft_printer(ft_swap_push(stack_b, stack_a));
		ft_checkpoint(stack_a, stack_b, vars);
		ft_checkpos(stack_a, stack_b, vars);
		ft_deletestack(&sorted);
	}
	ft_finalstep(stack_a, stack_b, vars);
}

//ANCHOR - SORT ALGO
void	ft_sortalgo(t_stack *stack_a, t_stack *stack_b)
{
	t_variables	*vars;
	t_list		*sorted;

	if (ft_isempty(stack_a->stack))
		return ;
	sorted = NULL;
	vars = ft_calloc(1, sizeof(t_variables));
	if (!vars)
		return ;
	vars->full_size = ft_lstsize(stack_a->stack);
	if (vars->full_size == 1)
		return ;
	if (ft_issorted(stack_a->stack, ASC) != TRUE)
		ft_shuffle(stack_a, stack_b, vars, sorted);
	free(vars);
}
//!SECTION