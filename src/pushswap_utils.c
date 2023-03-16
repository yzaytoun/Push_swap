/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:12:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/16 20:29:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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
void	ft_push(t_pushswap **top, int data)
{
	t_pushswap	*stack;

	stack = ft_calloc(1, sizeof(t_pushswap));
	if (!stack)
		return ;
	stack->num = data;
	stack->next = (*top);
	(*top) = stack;
}

//ANCHOR - Pop
int	ft_pop(t_pushswap **top)
{
	int			data;
	t_pushswap	*node;

	if (ft_isempty(*top))
		return (-1);
	node = (*top);
	(*top) = (*top)->next;
	data = node->num;
	free(node);
	return (data);
}

//ANCHOR - Is empty
int	ft_isempty(t_pushswap *top)
{
	return (top == NULL);
}

//ANCHOR - Get top
int	ft_gettop(t_pushswap *top)
{
	if (ft_isempty(top))
		return (-1);
	return (top->num);
}
