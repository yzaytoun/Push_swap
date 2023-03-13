/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:39:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/13 20:27:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//FIXME - To be deleted
void	ft_printstack(t_stack *a)
{
	t_stack	*top;

	if (ft_isempty(a))
		ft_printf("Empty Stack\n");
	top = a;
	while (top != NULL)
	{
		ft_printf(" %d\n", top->num);
		top = top->next;
	}
	ft_printf(" ---\n");
	ft_printf("stack_a\n\n");
}

//ANCHOR - Swap first two
//REVIEW - https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
int	ft_swap_first_two(t_stack **top)
{
	t_stack	*node;
	t_stack	*next;

	if (ft_isempty(*top) || ft_stacksize(*top) < 2)
		return ;
	node = (*top);
	next = (*top)->next;
	node->next = node->next->next;
	next->next = node;
	(*top) = next;
	return (1);
}

//ANCHOR - Adds the first node from stack_b to stack_a
int	ft_swap_push(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_isempty(*stack_a) || ft_isempty(*stack_b))
		return ;
	ft_push(stack_a, (*stack_b)->num);
	ft_pop(stack_b);
	return (2);
}

//ANCHOR - Rotate Stack
int	ft_swap_rotate(t_stack **top)
{
	t_stack	*node;
	t_stack	*newtop;

	if (ft_isempty(*top))
		return ;
	newtop = NULL;
	ft_push(&newtop, ft_gettop(*top));
	ft_pop(top);
	ft_reverse_stack(top);
	node = (*top);
	while (node != NULL)
	{
		ft_push(&newtop, node->num);
		node = node->next;
	}
	ft_deletestack(&node);
	(*top) = newtop;
	return (3);
}

//ANCHOR - Reverse Rotate
int	ft_swap_reverse_rotate(t_stack **top)
{
	t_stack	*node;
	t_stack	*newtop;
	int		last;

	last = 0;
	if (ft_isempty(*top))
		return ;
	newtop = NULL;
	last = ft_getlast(*top);
	node = (*top);
	while (node->next != NULL)
	{
		ft_push(&newtop, node->num);
		node = node->next;
	}
	ft_reverse_stack(&newtop);
	ft_push(&newtop, last);
	ft_deletestack(top);
	(*top) = newtop;
	return (4);
}

void	ft_printer(int signal)
{
	int	mov;

	mov = ft_classifier(signal);
	if (mov == SA)
		ft_printf("sa\n");
	if (mov == SB)
		ft_printf("sb\n");
	if (mov == SS)
		ft_printf("ss\n");
	if (mov == PA)
		ft_printf("pa\n");
	if (mov == PB)
		ft_printf("pb\n");
	if (mov == RA)
		ft_printf("ra\n");
	if (mov == RB)
		ft_printf("rb\n");
	if (mov == RR)
		ft_printf("rr\n");
	if (mov == RRA)
		ft_printf("rra\n");
	if (mov == RRB)
		ft_printf("rrb\n");
	if (mov == RRR)
		ft_printf("rrr\n");
}
