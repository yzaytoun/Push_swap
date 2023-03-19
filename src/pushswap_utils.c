/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:12:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/19 13:52:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION UTILS
//ANCHOR - Create Stack
t_stack	*ft_create_stack(int index)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->stack = NULL;
	node->index = index;
	return (node);
}

//ANCHOR - Push
void	ft_push(t_list **top, void *data)
{
	t_list	*stack;

	stack = ft_calloc(1, sizeof(t_list));
	if (!stack)
		return ;
	stack->content = data;
	stack->next = (*top);
	(*top) = stack;
}

//ANCHOR - Pop
int	ft_pop(t_list **top)
{
	int			data;
	t_list		*node;

	if (ft_isempty(*top))
		return (-1);
	node = (*top);
	(*top) = (*top)->next;
	data = (int)node->content;
	free(node);
	return (data);
}

//ANCHOR - Is empty
int	ft_isempty(t_list *top)
{
	return (top == NULL);
}

//ANCHOR - Get top
int	ft_gettop(t_list *top)
{
	if (ft_isempty(top))
		return (-1);
	return ((int)top->content);
}
//!SECTION*/