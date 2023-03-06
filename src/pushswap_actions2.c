/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_actions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:59:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/04 20:28:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
/*
pa : push a - toma el primer elemento del stack b y lo pone encima del stack a.
No hace nada si b está vacío.
pb : push b - toma el primer elemento del stack a y lo pone encima del stack b.
No hace nada si a está vacío
*/

//FIXME - To be deleted
void	ft_printstack(t_stack *a)
{
	t_stack	*top;

	top = a;
	while (top != NULL)
	{
		ft_printf("%d ", top->num);
		top = top->next;
	}
	ft_printf("\n");
}


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