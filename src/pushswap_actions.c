/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:39:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/25 12:52:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION ACTIONS
//FIXME - To be deleted
void	ft_printstack(t_list *a)
{
	t_list	*top;

	if (ft_isempty(a))
		ft_printf("Empty Stack\n");
	top = a;
	while (top != NULL)
	{
		ft_printf(" %d\n", (int)top->content);
		top = top->next;
	}
	ft_printf(" ---\n");
	ft_printf("stack_a\n\n");
}

//ANCHOR - Swap first two
int	ft_swap_first_two(t_stack **top)
{
	t_list	*node;
	t_list	*next;

	if (ft_isempty((*top)->stack) || ft_stacksize((*top)->stack) < 2)
		return (0);
	node = (*top)->stack;
	next = (*top)->stack->next;
	node->next = node->next->next;
	next->next = node;
	(*top)->stack = next;
	if ((*top)->index == 2)
		return (1 * 10);
	return (1);
}

//ANCHOR - Adds the first node from stack_b to stack_a
int	ft_swap_push(t_stack **to_stack, t_stack **from_stack)
{
	if (ft_isempty((*from_stack)->stack))
		return (0);
	ft_push(&(*to_stack)->stack,
		(void *)(uintptr_t)(*from_stack)->stack->content);
	ft_pop(&(*from_stack)->stack);
	if ((*to_stack)->index == 2)
		return (2 * 10);
	return (2);
}

//ANCHOR - Rotate Stack
int	ft_swap_rotate(t_stack **top)
{
	t_list	*node;
	t_list	*newtop;

	if (ft_isempty((*top)->stack))
		return (0);
	newtop = NULL;
	ft_push(&newtop, (void *)(uintptr_t)ft_gettop((*top)->stack));
	ft_pop(&(*top)->stack);
	ft_reverse_stack(&(*top)->stack);
	node = (*top)->stack;
	while (node != NULL)
	{
		ft_push(&newtop, node->content);
		node = node->next;
	}
	ft_deletestack(&node);
	(*top)->stack = newtop;
	if ((*top)->index == 2)
		return (3 * 10);
	return (3);
}

//ANCHOR - Reverse Rotate
int	ft_swap_reverse_rotate(t_stack **top)
{
	t_list		*node;
	t_list		*newtop;
	int			last;

	last = 0;
	if (ft_isempty((*top)->stack))
		return (0);
	newtop = NULL;
	last = ft_getlast((*top)->stack);
	node = (*top)->stack;
	while (node->next != NULL)
	{
		ft_push(&newtop, node->content);
		node = node->next;
	}
	ft_reverse_stack(&newtop);
	ft_push(&newtop, (void *)(uintptr_t)last);
	ft_deletestack(&(*top)->stack);
	(*top)->stack = newtop;
	if ((*top)->index == 2)
		return (4 * 10);
	return (4);
}

// ANCHOR - Printer
void	ft_printer(int signal)
{
	if (signal == 0)
		return ;
	if (signal == SA)
		ft_printf("sa\n");
	if (signal == SB)
		ft_printf("sb\n");
	if (signal == SS)
		ft_printf("ss\n");
	if (signal == PA)
		ft_printf("pa\n");
	if (signal == PB)
		ft_printf("pb\n");
	if (signal == RA)
		ft_printf("ra\n");
	if (signal == RB)
		ft_printf("rb\n");
	if (signal == RR)
		ft_printf("rr\n");
	if (signal == RRA)
		ft_printf("rra\n");
	if (signal == RRB)
		ft_printf("rrb\n");
	if (signal == RRR)
		ft_printf("rrr\n");
}

//!SECTION