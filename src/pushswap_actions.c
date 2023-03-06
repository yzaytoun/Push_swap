/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:59:33 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/06 18:48:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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

//FIXME - INCOMPLETE 
int	ft_swapnodes(t_stack **stac, int pos1, int pos2)
{
	t_stack	*first;
	t_stack	*second;

	if ((pos1 <= 0 || pos1 > ft_stacksize(*stac))
		|| (pos2 <= 0 || pos2 > ft_stacksize(*stac))
		|| ft_stacksize(*stac) == 0)
		return (-1);
	if (pos1 == pos2)
		return (EXIT_FAILURE);
	first = ft_getnode(*stac, pos1);
	second = ft_getnode(*stac, pos2);
	if (first != NULL && second != NULL)
	{
		ft_swapstacks(&first, &second);
		ft_swapstacks(&first->next, &second->next);
	}
	return (EXIT_SUCCESS);
}


//FIXME - INCOMPLETE 
void	ft_swapstacks(t_stack **stac1, t_stack **stac2)
{
	t_stack	*temp;

	temp = *stac1;
	(*stac1) = (*stac2);
	(*stac2) = temp;
}

void	ft_swap_rotate(t_stack **top)
{
	t_stack	*next;
	t_stack	*current;
	t_stack	*prev;

	next = NULL;
	prev = NULL;
	current = (*top);
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*top) = prev;
}
