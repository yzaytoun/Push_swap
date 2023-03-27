/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:10:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/27 18:27:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

/*void	ft_chunckstack(t_list *list_a, t_list *list_b, t_list *sorted)
{
	int	chunks;

	if (ft_isempty(list_a) || ft_isempty(list_b))
		return ;
	while (sorted != NULL)
	{
		if (ft_getpos(list_a, (void *)(uintptr_t)sorted->content)
			> ft_getpos(list_a, (void *)(uintptr_t)sorted->next->content))
		{
		}
		sorted = sorted->next;
	}
}
*/
void	ft_finalcheck(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	t_list	*node;

	(void)vars;
	if (ft_isempty(stack_a->stack))
		return ;
	node = stack_b->stack;
	if (ft_issorted(node, DESC) == TRUE
		&& ft_stacksize(node) > 0)
	{
		while (node != NULL)
		{
			ft_printer(ft_swap_push(&stack_a, &stack_b));
			node = node->next;
		}
	}
	else if (ft_issorted(stack_a->stack, ASC) != TRUE)
		ft_printer(ft_swap_push(&stack_b, &stack_a));
}
