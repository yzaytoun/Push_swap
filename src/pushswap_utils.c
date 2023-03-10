/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:12:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/09 20:08:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//ANCHOR - Create Stack
t_stack	*ft_create_stack(void)
{
	return (NULL);
}

//ANCHOR - Push
void	ft_push(t_stack **top, int data)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return ;
	node->num = data;
	node->next = (*top);
	(*top) = node;
}

//ANCHOR - Pop
int	ft_pop(t_stack **top)
{
	int		data;
	t_stack	*node;

	if (ft_isempty(*top))
		return (-1);
	node = (*top);
	(*top) = (*top)->next;
	data = node->num;
	free(node);
	return (data);
}

//ANCHOR - Is empty
int	ft_isempty(t_stack *top)
{
	return (top == NULL);
}

//ANCHOR - Get top
int	ft_gettop(t_stack *top)
{
	if (ft_isempty(top))
		return (-1);
	return (top->num);
}
