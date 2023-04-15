/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:26:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/15 19:12:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - SORT ALGO
int	ft_searchstack(t_list *list, int num)
{
	t_list	*node;

	node = list;
	while (node != NULL)
	{
		if ((int)node->content == num)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

//ANCHOR - Sort Only B
/*static void	ft_sortb(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	(void)stack_a;
	if (vars->last_b > vars->top_b)
		ft_printer(ft_swap_reverse_rotate(&stack_b));
	else if (vars->last_b > vars->revnext_b)
		ft_printer(ft_swap_reverse_rotate(&stack_b));
	else if (vars->top_b < vars->next_b)
		ft_printer(ft_swap_first_two(&stack_b));
	else if (vars->top_b < vars->last_b)
		ft_printer(ft_swap_rotate(&stack_b));
}/*/

//ANCHOR - GET Chunk - get ordered chunk and extract the closet number
static int	ft_getchunk(t_list *sorted, t_stack *stack,
	int (*func)(t_list *, int))
{
	int		count;
	t_list	*node;
	int		min_pos;

	count = 0;
	node = ft_copylist(sorted);
	if (ft_searchstack(stack->stack, (int)node->content) == TRUE)
		min_pos = (*func)(stack->stack, (int)node->content);
	else
		min_pos = (*func)(stack->stack, (int)node->next->content);
	while (count < 4 && node != NULL)
	{
		if (ft_searchstack(stack->stack, (int)node->content) == TRUE)
		{
			if (min_pos > (*func)(stack->stack, (int)node->content))
				min_pos = (*func)(stack->stack, (int)node->content);
		}
		else
		{
			if (min_pos > (*func)(stack->stack, (int)node->next->content))
				min_pos = (*func)(stack->stack, (int)node->next->content);
			node = node->next;
			++count;
		}
		node = node->next;
		++count;
	}
	ft_deletestack(&node);
	return (min_pos);
}

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
		vars->currpos = ft_getchunk(sorted, stack_a, &ft_getpos);
		vars->currrevpos = ft_getchunk(sorted, stack_a, &ft_getpos_rev);
		if (vars->currpos > vars->currrevpos)
			vars->curr = ft_getnum(stack_a->stack, vars->currrevpos);
		else
			vars->curr = ft_getnum(stack_a->stack, vars->currpos);
		ft_checkpoint(stack_a, stack_b, vars);
		while (vars->top_a != vars->curr)
		{
			if (vars->currpos > vars->currrevpos)
				ft_printer(ft_swap_reverse_rotate(&stack_a));
			else
				ft_printer(ft_swap_rotate(&stack_a));
			ft_checkpoint(stack_a, stack_b, vars);
		}
		ft_printer(ft_swap_push(stack_b, stack_a));
		ft_checkpoint(stack_a, stack_b, vars);
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