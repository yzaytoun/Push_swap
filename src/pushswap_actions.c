/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:39:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/09 20:42:53 by yzaytoun         ###   ########.fr       */
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
		ft_printf("%d ", top->num);
		top = top->next;
	}
	ft_printf("\n");
}

/*
https://stackoverflow.com/questions/73771635/singly-linked-list-swap-first-node-with-another-node
    Node *prev = *head, *cut;
    if( pos == 1 ) { // special case of 1st & 2nd swapping
        cut = prev->next;
        prev->next = prev->next->next;
        cut->next = prev;
    } else {
        while( --pos )
            prev = prev->next; // Now pointing at node AHEAD of node to swap out.

        cut  = prev->next;
        Node *cont = cut->next; // Now pointing at continuation (if any)
        cut->next = (*head)->next; // Now two heads
        prev->next = *head; // head spliced onto 1st section
        (*head)->next = cont; // old head joined to continuation
    }
    *head = cut; // This is the new head!
**/
//ANCHOR - Swap first two
//REVIEW - https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
void	ft_swap_first_two(t_stack **top)
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
}

//ANCHOR - Adds the first node from stack_b to stack_a
void	ft_swap_push(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_isempty(*stack_a) || ft_isempty(*stack_b))
		return ;
	ft_push(stack_a, (*stack_b)->num);
	ft_pop(stack_b);
}

/*ra : rotate a - desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
rb : rotate b - desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.
rr : rotate a y rotate b - desplaza al mismo tiempo todos los elementos del stack
a y del stack b una posición hacia arriba, de forma que el primer elemento se
convierte en el último.
rra : reverse rotate a - desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.7
rrb : reverse rotate b - desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr : reverse rotate a y reverse rotate b - desplaza al mismo tiempo todos
los elementos del stack a y del stack b una posición hacia abajo, de forma que
el último elemento se convierte en el prime*/

//ANCHOR - Rotate Stack
void	ft_swap_rotate(t_stack **top)
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
}

//FIXME - 
void	ft_swap_reverse_rotate(t_stack **top)
{
	t_stack	*node;
	t_stack	*newtop;

	if (ft_isempty(*top))
		return ;
	newtop = NULL;
	ft_push(&newtop, ft_getlast(*top));
	ft_pop(top);
	ft_reverse_stack(top);
	node = (*top);
	while (node->next != NULL)
	{
		ft_push(&newtop, node->num);
		node = node->next;
	}
	ft_deletestack(&node);
	(*top) = newtop;
}

