/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:22:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/20 20:19:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION MERGE
//ANCHOR - Get Next Element
void	ft_getnext_element(t_stack *stack_a, t_stack *stack_b,
	t_variables *vars)
{
	while (vars->top_a != vars->curr)
	{
		if (vars->currpos > vars->currrevpos)
			ft_printer(ft_swap_reverse_rotate(&stack_a));
		else
			ft_printer(ft_swap_rotate(&stack_a));
		ft_checkpoint(stack_a, stack_b, vars);
	}
	ft_checkpoint(stack_a, stack_b, vars);
}

//ANCHOR Split stack
static void	ft_splitstack(t_list *stack, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	if (ft_isempty(stack))
		return ;
	slow = stack;
	fast = stack->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = stack;
	*back = slow->next;
	slow->next = NULL;
}

//ANCHOR Join stack
static t_list	*ft_joinstacks(t_list *stac_a, t_list *stac_b)
{
	t_list	*top;

	if (stac_a == NULL)
		return (stac_b);
	else if (stac_b == NULL)
		return (stac_a);
	top = NULL;
	if ((int)stac_a->content <= (int)stac_b->content)
	{
		top = stac_a;
		top->next = ft_joinstacks(stac_a->next, stac_b);
	}
	else
	{
		top = stac_b;
		top->next = ft_joinstacks(stac_a, stac_b->next);
	}
	return (top);
}

//ANCHOR Merge sort
void	ft_mergesort(t_list **stack)
{
	t_list	*top;
	t_list	*part1;
	t_list	*part2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	ft_splitstack(top, &part1, &part2);
	ft_mergesort(&part1);
	ft_mergesort(&part2);
	(*stack) = ft_joinstacks(part1, part2);
}

//ANCHOR Copy List
t_list	*ft_copylist(t_list *list)
{
	t_list	*new;
	t_list	*node;

	node = list;
	if (ft_isempty(list))
		return (NULL);
	else
	{
		new = ft_lstnew(node->content);
		new->next = ft_copylist(list->next);
	}
	return (new);
}

//!SECTION